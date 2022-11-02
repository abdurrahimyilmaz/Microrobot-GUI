
#include "stdio.h"

#include "Dynamixel.h"
#include "SerialPort.h"
#include "AX12A_VARIABLES.h"

Dynamixel::Dynamixel(byte motorID)
{
	ID = motorID;
	cleanBuffers();
}

Dynamixel::Dynamixel(const wchar_t *portName, byte motorID) {
	ID = motorID;
	port->connect(portName);
	cleanBuffers();
}

Dynamixel::Dynamixel(byte motorID, SerialPort* ptrPort) {
	port = ptrPort;
	ID = motorID;
	cleanBuffers();
}
Dynamixel::Dynamixel() {
	ID = 2;
	cleanBuffers();
}
Dynamixel::~Dynamixel()
{
	port->disconnect();
	cleanBuffers();
}


void Dynamixel::cleanBuffers()
{
	memset(buffer, 0, BufferSize);
	memset(bufferIn, 0, BufferSize);
}


void Dynamixel::toHexHLConversion(short pos, byte *hexH, byte *hexL)
{
	*hexH = (byte)(pos >> 8);
	*hexL = (byte)pos;
}

short Dynamixel::fromHexHLConversion(byte hexH, byte hexL)
{
	return (short)((hexL << 8) + hexH);
}

byte Dynamixel::CalculateCheckSum(byte  data[], int length)
{
	int cs = 0;
	for (int i = 2; i < length; i++)
	{
		cs += data[i];
	}
	return (byte)~cs;
}



int Dynamixel::getReadPositionCommand()
{
	//OXFF AX_START_COMMAND ID LENGTH INSTRUCTION PARAMETER1 …PARAMETER N CHECK SUM
	int pos = 0;

	buffer[pos++] = AX_START_COMMAND;
	buffer[pos++] = AX_START_COMMAND;
	buffer[pos++] = ID;

	// AX_POSITION_LENGTH
	buffer[pos++] = AX_POSITION_LENGTH + AX_BYTE + AX_BYTE; 

	//the instruction, read => 2
	buffer[pos++] = AX_READ_DATA;

	// pos registers 36 and 37
	buffer[pos++] = AX_POSITION_PRESENT;

	//bytes to read
	buffer[pos++] = AX_POSITION_LENGTH;

	byte checksum = CalculateCheckSum(buffer, pos);
	buffer[pos++] = checksum;

	return pos;
}
int Dynamixel::getWriteSpeedCommand(short goal) {
	int pos = 0;
	byte numberOfParameters = 0;
	

	buffer[pos++] = AX_START_COMMAND;
	buffer[pos++] = AX_START_COMMAND;
	buffer[pos++] = ID;

	// placeholder byte
	buffer[pos++] = 0; 

	buffer[pos++] = AX_WRITE_DATA;


	buffer[pos++] = AX_SPEED_ADRESS;

	
	byte hexH = 0;
	byte hexL = 0;

	toHexHLConversion(goal, &hexH, &hexL);
	buffer[pos++] = hexL;
	numberOfParameters++;
	buffer[pos++] = hexH;
	numberOfParameters++;

	// bodyLength
	buffer[3] = (byte)(numberOfParameters + 3*AX_BYTE);

	byte checksum = CalculateCheckSum(buffer, pos);
	buffer[pos++] = checksum;

	return pos;
}
int Dynamixel::getWritePositionCommand(short goal)
{
	int pos = 0;
	byte numberOfParameters = 0;
	//OXFF AX_START_COMMAND ID LENGTH INSTRUCTION PARAMETER1 …PARAMETER N CHECK SUM

	buffer[pos++] = AX_START_COMMAND;
	buffer[pos++] = AX_START_COMMAND;
	buffer[pos++] = ID;

	// PLACE HOLDER
	buffer[pos++] = 0; 

					   
	buffer[pos++] = AX_WRITE_DATA;

	
	buffer[pos++] = AX_POSITION_GOAL;

	
	byte hexH = 0;
	byte hexL = 0;
	toHexHLConversion(goal, &hexH, &hexL);
	buffer[pos++] = hexL;
	numberOfParameters++;
	buffer[pos++] = hexH;
	numberOfParameters++;

	// bodyLength
	buffer[3] = (byte)(numberOfParameters + 3);

	byte checksum = CalculateCheckSum(buffer, pos);
	buffer[pos++] = checksum;

	return pos;
}



int Dynamixel::getPosition(){
	int ret = 0;

	int n = getReadPositionCommand();
	long l = port->sendArray(buffer, n);

	Sleep(waitTime);

	memset(bufferIn, 0, BufferSize);

	n = port->getArray(bufferIn, 8);

	short pos = -1;
	if (n>7)
	{
		pos = fromHexHLConversion(bufferIn[POS_AX_PROPERTY_ID - AX_BYTE], bufferIn[POS_AX_NEW_PROPERTY_VAL - AX_BYTE]);
	}

	
	if (pos<AX_POSITION_LOWER || pos > AX_POSITION_UPPER)
	//position set error
		ret = -2;
	else
		ret = pos;


	return ret;
}

int Dynamixel::setPosition(int position){
	int error = 0;

	int n = getWritePositionCommand(position);
	long l = port->sendArray(buffer, n);
	Sleep(waitTime);

	memset(bufferIn, 0, BufferSize);
	n = port->getArray(bufferIn, 8);



	if (n > 4 && bufferIn[4] == 0);
	else {
		//motor position didn't end up well.
		error = -1;
	}

	return error;
}

int Dynamixel::sendTossModeCommand()
{
	byte tossModeCommandBuffer[15];
	tossModeCommandBuffer[0] = 't';
	tossModeCommandBuffer[1] = '\n';
	tossModeCommandBuffer[2] = 0;

	int n = port->sendArray(tossModeCommandBuffer, 2);
	Sleep(200);

	port->clear();
	Sleep(5);

	return n;
}

void Dynamixel::bf(byte *buffer, int n)
{
	printf("Response (length <%i>)\n", n);
	for (int i = 0; i<n; i++)
	{
		//printf("%i [%c]", buffer[i], buffer[i]);
		printf("%i", buffer[i]);
		if (i<(n - 1))
		{
			printf(",", buffer[i]);
		}
	}
	printf("\n");
}


int Dynamixel::getReadSpeedCommand() {
	int pos = 0;

	buffer[pos++] = AX_START_COMMAND;
	buffer[pos++] = AX_START_COMMAND;
	buffer[pos++] = ID;

	// length = 4
	buffer[pos++] = AX_SPEED_LENGTH + 2*AX_BYTE; //placeholder
	
	buffer[pos++] = AX_READ_DATA;

	// pos registers 36 and 37
	buffer[pos++] = AX_SPEED_ADRESS;

	//bytes to read
	buffer[pos++] = AX_SPEED_LENGTH;

	byte checksum = CalculateCheckSum(buffer, pos);
	buffer[pos++] = checksum;

	return pos;

} 

int Dynamixel::getSpeedValue() {
	int ret = 0;

	int n = getReadSpeedCommand();
	long l = port->sendArray(buffer, n);

	Sleep(waitTime);

	memset(bufferIn, 0, BufferSize);

	n = port->getArray(bufferIn, 8);

	short pos = -1;
	if (n>7)
	{
		pos = fromHexHLConversion(bufferIn[POS_AX_PROPERTY_ID - AX_BYTE], bufferIn[POS_AX_NEW_PROPERTY_VAL - AX_BYTE]);
	}


	if (pos<AX_SPEED_LOWER || pos > AX_SPEED_UPPER)
		//position set error
		ret = -2;
	else
		ret = pos;


	return ret;
}

int Dynamixel::setSpeedValue(short goal) {

	int error = 0;

	int n = getWriteSpeedCommand(goal);
	long l = port->sendArray(buffer, n);
	Sleep(waitTime);

	memset(bufferIn, 0, BufferSize);
	n = port->getArray(bufferIn, 8);

	if (n > 4 && bufferIn[4] == 0);
	else {
		error = -1;
		bf(bufferIn, n);
	}

	return error;

}

void Dynamixel::setPort(const wchar_t* portName) {
	port->connect(portName);
}