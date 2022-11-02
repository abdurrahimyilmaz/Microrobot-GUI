
#include "stdio.h"

#include "PI_GCS2_DLL.h"
#include "Stage.h"
#include <stdio.h>
#include <iostream>
#include "MEDAQLib.h"
#include <conio.h>
#include <windows.h>
#include <string>
#include <array>
#include <fstream>
#include "Stage.h"

#include "Form1.h"

Stage* Stage::stageInstance = nullptr;

Stage::Stage(bool& measureStatement):
	measureStatement(&measureStatement)
{
	
}

Stage::~Stage()
{
	
}

bool Stage::Connect()
{
	id = PI_InterfaceSetupDlg('\0');
	
	if (id > -1) {
		CompleteConnection();
		return true;
	}

	return false;
}

void Stage::CompleteConnection()
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

	MoveAxis(StageAxisX, 5);
	MoveAxis(StageAxisY, 5);
	MoveAxis(StageAxisZ, 5);
}

void Stage::SetServo(const char* axis, bool onmu) 
{
	int kontrol[1];

	kontrol[0] = (onmu ? 1 : 0);

	PI_SVO(id, axis, kontrol);
}

bool Stage::MoveAxis(const char* axis, double value)
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

	while (Ismoving());

}

void Stage::SetStep(const char* axis, double step)
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

bool Stage::SetStep1(const char* axis, double step) 
{
	if (step < MOVE_LOWER_LIMIT || step > MOVE_UPPER_LIMIT)
		return false;

	int iChnl[2];
	iChnl[0] = 0;
	int iPar[2];
	iPar[0] = 1;

	PI_DRT(id, iChnl, iPar, "0", 1);
	double dVals[] = { step };

	PI_MOV(id, axis, dVals);

	return true;

}

void Stage::ResetSpeed(const char* axis)
{
	double vals[] = { 0.1 };
	PI_VEL(id, axis, vals);
}

void Stage::StepLeft(const char* axis)
{
	MoveAxis(axis, currentTarget[atoi(axis) - 1] - axisSteps[(atoi)(axis) - 1]);
}

void Stage::StepRight(const char* axis)
{
	MoveAxis(axis, currentTarget[(atoi)(axis) - 1] + axisSteps[(atoi)(axis) - 1]);
}

void Stage::FullLeft(const char* axis)
{
	MoveAxis(axis, 0);
}

void Stage::FullRight(const char* axis)
{
	MoveAxis(axis, 20);
}

void Stage::UpdateTargetPositions()
{
	PI_qMOV(id, "1 2 3", currentTarget);	//axis verilmesi gerekiyor
}

void Stage::UpdatePositionsStepSizeandVel(std::string textvel, std::string textss, const char* axis, std::string textpos, std::string texttar)
{
	double vel[] = {std::stod(textvel)};

	axisSteps[(atoi)(axis) - 1] = std::stod(textss);

	PI_VEL(id, axis, vel);

	//PI_qVEL(id, axis, velgel);
	PI_qPOS(id, axis, currentPos);
	PI_qMOV(id, axis, currentTarget);

	//	textvel->Text = Convert::ToString(currentTarget[(int)(axis) - 1]);
	texttar = std::to_string(currentTarget[atoi(axis) - 1]);
	textpos = std::to_string(currentPos[atoi(axis) - 1]);
}

bool Stage::Ismoving()
{
	PI_IsMoving(id, "1", ismoving[x]);
	PI_IsMoving(id, "2", ismoving[y]);
	PI_IsMoving(id, "3", ismoving[z]);

	if (*ismoving[x] == true || *ismoving[y] == true || *ismoving[z] == true)
	{
		*measureStatement = false;
		return true;
	}
	else
	{
		*measureStatement = true;
		return false;
	}
}

Stage* Stage::getInstance(bool& Statement)
{
	if (stageInstance == nullptr)
	{
		stageInstance = new Stage(Statement);
	}

	return stageInstance;
}