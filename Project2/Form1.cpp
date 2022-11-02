#include "Form1.h"
#include "PI_GCS2_DLL.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MEDAQLib.h"
#include <assert.h>
#include <string>
#include <fstream>
#include <fstream>
#include "AX12A_VARIABLES.h"
#include "Dynamixel.h"
#include "SerialPort.h"
#include <memory>
#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Threading;

//using namespace std;


#define SETSERVO(STRING_NAME)                      \
  if (ServoComConnected == true)        \
    STRING_NAME = new Dynamixel(ID_##STRING_NAME, port);  \
  else {              \
    port->connect(wCOM);        \
    STRING_NAME = new Dynamixel(ID_##STRING_NAME, port);  \
    ServoComConnected = true;     \
  }       		

#define GETSERVOID(STRING_NAME) \
	ID_##STRING_NAME		
\







#pragma region Tanýmlamalar

constexpr int EXPECTED_BLOCK_SIZE = 1000;
int connectionError = 0;

HINSTANCE hInstance = LoadLibrary(L"MEDAQLib.dll");
DWORD sensor = CreateSensorInstance(SENSOR_ILD2300);
int id;



bool ServoComConnected = false;
SerialPort* port = new SerialPort();

Dynamixel* ALT_MOTOR;

Dynamixel* UST_MOTOR;

#pragma endregion

[STAThread]


void main(array<System::String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	Project2::Form1 form;		
	
	//const char* sdf = '\0';
	//PI_InterfaceSetupDlg(sdf);	
	
	Application::Run(%form);
	
}

void Project2::Form1::btnLz_click_event(Button^ buton, TextBox^ text, ComboBox^ cbox)
{
	cbox->Enabled = true;
	
	csvData.open("nokta-lazer-veri.csv");

	connectionError = SetParameterString(sensor, "IP_Interface", "TCP/IP");
	assert(!connectionError);

	connectionError = SetParameterString(sensor, "IP_RemoteAddr", "169.254.168.150");
	assert(!connectionError);

	connectionError = SetParameterInt(sensor, "IP_EnableLogging", 0);
	assert(!connectionError);

	connectionError = SetParameterString(sensor, "IP_LogFile", "c:/MEDAQLib-log.txt");
	assert(!connectionError);
	 
	int err = OpenSensor(sensor);
	int currentlyAvailable = 0;

	while (1) {
		err = DataAvail(sensor, &currentlyAvailable);

		if (currentlyAvailable < EXPECTED_BLOCK_SIZE) {
			int rawData[EXPECTED_BLOCK_SIZE];
			double scaledData[EXPECTED_BLOCK_SIZE];

			int expectedBlockSize = EXPECTED_BLOCK_SIZE;
			int gotBlockSize = 0;

			err = TransferData(sensor, rawData, scaledData, expectedBlockSize, &gotBlockSize);

			if (rawData[currentlyAvailable] > 0)
			{
				Application::DoEvents();
				text->Text = Convert::ToString(rawData[currentlyAvailable]);
				csvData << rawData[currentlyAvailable]<<"\n";
				std::cout << (rawData[currentlyAvailable]) << "\n";
			}

			currentlyAvailable++;
			
			if (currentlyAvailable == EXPECTED_BLOCK_SIZE - 1)
				currentlyAvailable = 0;
		}
		else
			break;
	}	
	
	CloseSensor(sensor);
	ReleaseSensorInstance(sensor);

	std::cin.get();
}

void Project2::Form1::lazerKapat()
{
	CloseSensor(sensor);
	ReleaseSensorInstance(sensor);
}

void Project2::Form1::cbbLz_indexchange_event(ComboBox^ cbox, Label^ label)
{
	double deger = Convert::ToDouble(cbox->SelectedItem);

	label->Text = "Frekans: " + Convert::ToString(deger) + " kHz";

	SetDoubleExecSCmd(sensor, "Set_Samplerate", "SP_Measrate", deger);	

	
}

bool Project2::Form1::btnSt_click_event(Button^ buton, TextBox^ textx, TextBox^ texty, TextBox^ textz)
{
	id = PI_InterfaceSetupDlg('\0');

	if (id > -1) {
		CompleteConnection();		
		return true;
	}

	return false;
}

void Project2::Form1::btnStIncX_click_event(Button^ buton)
{
	
}

void Project2::Form1::CompleteConnection()
{
	char szBuffer[256];

	PI_qIDN(id, szBuffer, 255);

	//idn atamasý burada yapýlacak

	PI_qSAI_ALL(id, szBuffer, strlen(szBuffer));

	SetServo(StageAxisX, true);
	SetServo(StageAxisY, true);
	SetServo(StageAxisZ, true);

	axisSteps[0] = (double)5;
	axisSteps[1] = (double)5;
	axisSteps[2] = (double)5;


	PI_VEL(id, "1", &axisSteps[0]);
	PI_VEL(id, "2", &axisSteps[1]);
	PI_VEL(id, "3", &axisSteps[2]);

	MoveAxis(StageAxisX, 18);
	MoveAxis(StageAxisY, 5);
	MoveAxis(StageAxisZ, 9);
}

void Project2::Form1::SetServo(const char* axis, bool onmu)
{
	int kontrol[1];

	kontrol[0] = (onmu ? 1 : 0);

	PI_SVO(id, axis, kontrol);
}

bool Project2::Form1::MoveAxis(const char* axis, double value)
{
	if (value < MOVE_LOWER_LIMIT || value > MOVE_UPPER_LIMIT)
		return false;

	int iChnl[2];
	iChnl[0] = 0;
	int iPar[2];
	iPar[0] = 1;

	PI_DRT(id, iChnl, iPar, "0", 1);

	double dVals[] = { value };

	PI_MOV(id, axis, dVals);
}

void Project2::Form1::SetStep(const char* axis, double step)
{
	if (step > STEP_MAX || step < STEP_MIN)
		return;

	if (*axis == '1')
	{
		axisSteps[0] = step;
		
	}
	else if (*axis == '2')
	{
		axisSteps[1] = step;
	}
	else if (*axis == '3')
	{
		axisSteps[2] = step;
	}
	
}

bool Project2::Form1::SetStep1(const char* axis, double step)
{
	if (step < MOVE_LOWER_LIMIT || step > MOVE_UPPER_LIMIT)
		return false;

	int iChnl[2];
	iChnl[0] = 0;
	int iPar[2];
	iPar[0] = 1;

	PI_DRT(id, iChnl, iPar, "0", 1);
	double dVals[]= { step };

	PI_MOV(id, axis, dVals);

	return true;

}



void Project2::Form1::ResetSpeed(const char* axis)
{
	double vals[] = { 0.1 };
	PI_VEL(id, axis, vals);
}

void Project2::Form1::StepLeft(const char* axis)
{		

	MoveAxis(axis, currentTarget[Convert::ToInt32(axis) - 1] - axisSteps[Convert::ToInt32(axis) - 1]);
}

void Project2::Form1::StepRight(const char* axis)
{
	MoveAxis(axis, currentTarget[Convert::ToInt32(axis) - 1] + axisSteps[Convert::ToInt32(axis) - 1]);
}

void Project2::Form1::FullLeft(const char* axis)
{
	MoveAxis(axis, 0);
}

void Project2::Form1::FullRight(const char* axis)
{
	MoveAxis(axis, 20);
}

void Project2::Form1::UpdateTargetPositions()
{
	PI_qMOV(id, "1 2 3", currentTarget);	//axis verilmesi gerekiyor
}

void Project2::Form1::UpdatePositionsStepSizeandVel(TextBox^ textvel, TextBox^ textss, const char* axis, TextBox^ textpos, TextBox^ texttar)
{
	double vel[] = { Convert::ToDouble(textvel->Text) };	
	
	axisSteps[Convert::ToInt32(axis) - 1] = Convert::ToDouble(textss->Text);	

	PI_VEL(id, axis, vel);

	//PI_qVEL(id, axis, velgel);
	PI_qPOS(id, axis, currentPos);
	PI_qMOV(id, axis, currentTarget);

//	textvel->Text = Convert::ToString(currentTarget[Convert::ToInt32(axis) - 1]);
	texttar->Text = Convert::ToString(currentTarget[Convert::ToInt32(axis) - 1]);
	textpos->Text = Convert::ToString(currentPos[Convert::ToInt32(axis) - 1]);
}





//DYNAMIXEL SERVOS
void Project2::Form1::btnSvDondur_click_event(Button^btnSvDondur, TextBox^XtxtSvRpm, TextBox^XtxtSvDerece, std::string ServoName) {
	int speed = 0;
	int degree = 0;

	/*
	DYNAMÝXEL KÜTÜPHANESÝ 0-1024 ARASINDA VERÝ KABUL EDÝYOR. KULLANICI DOSTU OLMASI ÝÇÝN ARAYÜZ
	AÇI DEÐERÝ KABUL EDÝYOR. AÞAÐIDA EL ÝLE YAPILMIÞ BÝR MAPPÝNG VAR.
	*/

	if (XtxtSvRpm->Text != "")
		speed = System::Convert::ToInt32(XtxtSvRpm->Text);

	if (XtxtSvDerece->Text != "")
		degree = System::Convert::ToInt32(XtxtSvDerece->Text);



	if (speed < AX_RPM_LOWER)
		speed = AX_RPM_LOWER;
	else if (speed > AX_RPM_UPPER)
		speed = AX_RPM_UPPER;

	speed = speed*(AX_SPEED_UPPER / AX_RPM_UPPER);

	if (degree < AX_POS_DEG_LOWER)
		degree = AX_POS_DEG_LOWER;
	else if (degree > AX_POS_DEG_UPPER)
		degree = AX_POS_DEG_UPPER;

	degree = AX_POS_MIDDLE + degree*(AX_POSITION_UPPER / AX_ROTATING_ANGLE);


	if (ServoName == "ALT") {
		ALT_MOTOR->setSpeedValue((short)speed);
		ALT_MOTOR->setPosition(degree);
	}
	else if (ServoName == "UST") {
		UST_MOTOR->setSpeedValue((short)speed);
		UST_MOTOR->setPosition(degree);
	}
	else if (ServoName == "SYNC") {
		ALT_MOTOR->setSpeedValue((short)speed);
		UST_MOTOR->setSpeedValue((short)speed);

		ALT_MOTOR->setPosition(degree);
		UST_MOTOR->setPosition(degree);
	}

}

void Project2::Form1::btnSvOrtala_click_event(Button^btnSvOrtala, std::string ServoName) {

	
	if (ServoName == "ALT") {
		ALT_MOTOR->setSpeedValue(AX_SPEED_UPPER);
		ALT_MOTOR->setPosition(AX_POS_MIDDLE);
	}
	else if (ServoName == "UST") {
		UST_MOTOR->setSpeedValue(AX_SPEED_UPPER);
		UST_MOTOR->setPosition(AX_POS_MIDDLE);
	}
	else if (ServoName == "SYNC") {
		UST_MOTOR->setSpeedValue(AX_SPEED_UPPER);
		ALT_MOTOR->setSpeedValue(AX_SPEED_UPPER);

		ALT_MOTOR->setPosition(AX_POS_MIDDLE);
		UST_MOTOR->setPosition(AX_POS_MIDDLE);
	}
}


void Project2::Form1::btnServo_click_event(Button^btnServo, TextBox^XtxtSvRpm, TextBox^XtxtSvDerece, Button^XbtnSvDondur, Button^XbtnSvOrtala, TextBox^XtxtSvCom,TextBox^ustServoCheck, std::string ServoName) {
	std::wstring COM = L"COM";

	COM += std::to_wstring(System::Convert::ToInt32(XtxtSvCom->Text));

	const wchar_t* wCOM = COM.c_str();
	

	if (ServoName == "ALT") {
		SETSERVO(ALT_MOTOR);
	}
	else if (ServoName == "UST") {
		SETSERVO(UST_MOTOR);
	}
	else if (ServoName == "SYN") {
		SETSERVO(UST_MOTOR);
		SETSERVO(ALT_MOTOR);
	}

	XtxtSvRpm->Enabled = true;
	XtxtSvDerece->Enabled = true;
	XbtnSvDondur->Enabled = true;
	XbtnSvOrtala->Enabled = true;
}
