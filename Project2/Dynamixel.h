
#ifndef DYNAMIXEL_H_
#define DYNAMIXEL_H_

typedef unsigned char byte;

#include "SerialPort.h"

class Dynamixel {
private:
	SerialPort* port;
	static const int BufferSize = 1024;
	static const int waitTime = 10;
	
	byte checksum = 0;
	byte ID;
	unsigned int position;
	unsigned int speed;

	byte buffer[BufferSize];
	byte bufferIn[BufferSize];

	void cleanBuffers();
	void toHexHLConversion(short pos, byte *hexH, byte *hexL);
	short fromHexHLConversion(byte hexH, byte hexL);

	byte CalculateCheckSum(byte data[], int length);
	
	int getWritePositionCommand(short goal);
	int getReadPositionCommand();

	int getWriteSpeedCommand(short goal);
	int getReadSpeedCommand();

public:

	Dynamixel(const wchar_t *portName,byte motorID);
	Dynamixel( byte motorID, SerialPort* ptrPort);
	Dynamixel(byte motorID);
	Dynamixel();
	~Dynamixel();

	int getPosition();
	int setPosition(int goal);

	int getSpeedValue();
	int setSpeedValue(short goal);

	int sendTossModeCommand();

	void bf(byte *buffer, int n);
	void setPort(const wchar_t* portName);
};

#endif