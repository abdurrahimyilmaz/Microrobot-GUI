
#ifndef  STAGE_H
#define STAGE_H

#include <memory>
#include "PI_GCS2_DLL.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include "MEDAQLib.h"
#include <conio.h>
#include <windows.h>
#include <string>
#include <array>
#include <fstream>
#include "Form1.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace System::Windows::Forms;


class Stage
{

private:
	int id;
	void CompleteConnection();
	bool Connect();
	double currentPos[3];
	double currentTarget[3];
	double axisSteps[3];
	const char* StageAxisX = "1";
	const char* StageAxisY = "2";
	const char* StageAxisZ = "3";	
	BOOL* ismoving[] = { false, false, false };
	

	std::shared_ptr<bool> measureStatement;

	Stage(bool& measureStatement);
	Stage() = delete;
	Stage(Stage&) = delete;
	Stage(Stage&&) = delete;
	
	Stage& operator=(Stage) = delete;
	
	static Stage* stageInstance;
	
public:	
	static Stage* getInstance(bool&measureStatement);
	~Stage();
	void SetServo(const char* axis, bool onmu);
	bool MoveAxis(const char* axis, double value);
	void SetStep(const char* axis, double step);
	bool SetStep1(const char* axis, double step);
	void ResetSpeed(const char* axis);
	void StepLeft(const char* axis);
	void StepRight(const char* axis);
	void FullLeft(const char* axis);
	void FullRight(const char* axis);
	void UpdateTargetPositions();
	void UpdatePositionsStepSizeandVel(std::string textvel, std::string textss, const char* axis, std::string textpos, std::string texttar);
	bool Ismoving();
	enum axis { x = 0; y = 1; z = 2; };

};

#endif // ! STAGE_H



