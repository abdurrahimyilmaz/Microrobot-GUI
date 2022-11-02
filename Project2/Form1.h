#pragma once

#include <stdio.h>
#include <iostream>
#include "MEDAQLib.h"
#include <conio.h>
#include <windows.h>
#include <string>
#include <array>
#include <fstream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include "FlyCapture2.h"




FlyCapture2::Camera camera;
FlyCapture2::CameraInfo camInfo;
FlyCapture2::Error error;
FlyCapture2::BusManager bus;
FlyCapture2::Image rawImage;
FlyCapture2::Image bitmapSource;
FlyCapture2::Image rgbImage;
cv::Mat image;

using namespace FlyCapture2;
using namespace cv;

std::ofstream csvData;


std::string ALT_SERVO_STR_ID = "UST";
std::string UST_SERVO_STR_ID = "ALT";
std::string SENKRON_SERVO_STR_ID = "SYN";

const char* StageAxisX = "1";
const char* StageAxisY = "2";
const char* StageAxisZ = "3";

constexpr double MOVE_UPPER_LIMIT = 20.0;
constexpr double MOVE_LOWER_LIMIT = 0.0;
constexpr double STEP_DELTA = 0.01;
constexpr double STEP_MIN = 0.0;
constexpr double STEP_MAX = 10.0;
constexpr double STEP_INITIAL = 3;

double currentPos[3];
double currentTarget[3];
double axisSteps[3];


namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Windows::Forms;
	
	
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:		
		void btnLz_click_event(Button^, TextBox^, ComboBox^);
		void cbbLz_indexchange_event(ComboBox^, Label^);
		bool btnSt_click_event(Button^, TextBox^, TextBox^, TextBox^);
		void btnStIncX_click_event(Button^);
		void CompleteConnection();
		void SetServo(const char* , bool );
		bool MoveAxis(const char* , double );		
		void SetStep(const char*, double);
		void ResetSpeed(const char* );
		void StepLeft(const char* );
		void StepRight(const char* );
		void FullLeft(const char*);
		void FullRight(const char*);
		void UpdatePositionsStepSizeandVel(TextBox^, TextBox^, const char*, TextBox^, TextBox^ );
		void UpdateTargetPositions();
		bool SetStep1(const char*, double);
		void lazerKapat();

		void btnSvDondur_click_event(Button^ btnSvDondur, TextBox^ XtxtSvRpm, TextBox^XtxtSvDerece,std::string ServoName);
		void btnSvOrtala_click_event(Button^btnSvOrtala, std::string ServoName);
		void btnServo_click_event(Button^btnServo, TextBox^XtxtSvRpm, TextBox^XtxtSvDerece, Button^XbtnSvDondur, Button^XbtnSvOrtala, TextBox^XtxtSvCom,TextBox^ustServoCheck, std::string ServoName);


		
		Form1(void)
		{
			InitializeComponent();
			
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnLazer;
	private: System::Windows::Forms::TextBox^  txtLzUzaklik;
	protected:

	protected:

	protected:


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ComboBox^  cbbLzHz;
	private: System::Windows::Forms::Label^  lblLzUzaklik;













	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  lblStY;

	private: System::Windows::Forms::Label^  lblStX;
	private: System::Windows::Forms::Label^  lblStZ;
















	private: System::Windows::Forms::Button^  btnStMZ;



	private: System::Windows::Forms::Button^  btnStIncZ;


	private: System::Windows::Forms::Button^  btnStDecX;


	private: System::Windows::Forms::Button^  btnStLX;
	private: System::Windows::Forms::Button^  btnStDecY;
	private: System::Windows::Forms::Button^  btnStMY;
	private: System::Windows::Forms::Button^  btnStDecZ;




	private: System::Windows::Forms::Button^  btnStLY;




	private: System::Windows::Forms::Button^  btnStLZ;

	private: System::Windows::Forms::Button^  btnStIncY;




	private: System::Windows::Forms::Button^  btnStMX;
	private: System::Windows::Forms::Button^  btnStIncX;
private: System::Windows::Forms::TextBox^  txtStVelX;
private: System::Windows::Forms::TextBox^  txtStVelY;




private: System::Windows::Forms::TextBox^  txtStPosX;
private: System::Windows::Forms::TextBox^  txtStVelZ;


private: System::Windows::Forms::TextBox^  txtStPosY;

private: System::Windows::Forms::TextBox^  txtStStepSizeX;
private: System::Windows::Forms::TextBox^  txtStPosZ;


private: System::Windows::Forms::TextBox^  txtStStepSizeY;
private: System::Windows::Forms::TextBox^  txtStStepSizeZ;


	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  lblSvDerece;

	private: System::Windows::Forms::Label^  lblSvRpm;

	private: System::Windows::Forms::Label^  lblSvCom;
	private: System::Windows::Forms::TextBox^  txtSvDerece;


	private: System::Windows::Forms::TextBox^  txtSvRpm;

	private: System::Windows::Forms::Button^  btnSvOrtala;

	private: System::Windows::Forms::Button^  btnServo;
private: System::Windows::Forms::TextBox^  txtSvCom;



	private: System::Windows::Forms::Button^  btnSvDondur;
private: System::Windows::Forms::Label^  lblStVel;

private: System::Windows::Forms::Label^  lblStPos;



private: System::Windows::Forms::Label^  lblStStepSize;


private: System::Windows::Forms::Button^  btnStCon;
private: System::Windows::Forms::Label^  lblLzFrekans;
private: System::Windows::Forms::Timer^  timerStage;

private: System::Windows::Forms::TextBox^  txtStTargetX;
private: System::Windows::Forms::TextBox^  txtStTargetY;
private: System::Windows::Forms::TextBox^  txtStTargetZ;
private: System::Windows::Forms::Label^  label1;


private: System::Windows::Forms::Button^  kameraBaslat;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::Timer^  timerKamera;
private: System::Windows::Forms::TabControl^  tabControl1;
private: System::Windows::Forms::TabPage^  anaMenu;
private: System::Windows::Forms::TabPage^  yardim;
private: System::Windows::Forms::RichTextBox^  richTextBox1;
private: System::Windows::Forms::Button^  kameraKapat;
private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::TextBox^  txtSvDereceUst;
private: System::Windows::Forms::TextBox^  txtSvRpmUst;
private: System::Windows::Forms::Button^  btnSvOrtalaUst;
private: System::Windows::Forms::Button^  btnServoUst;
private: System::Windows::Forms::TextBox^  txtSvComUst;
private: System::Windows::Forms::Button^  btnSvDondurUst;
private: System::Windows::Forms::TabControl^  tabControl2;
private: System::Windows::Forms::TabPage^  tabPage1;
private: System::Windows::Forms::TabPage^  tabPage2;
private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::TextBox^  txtSrvSyncDeg;

private: System::Windows::Forms::TextBox^  txtSrvSynRpm;

private: System::Windows::Forms::Button^  btnSrvSynReset;

private: System::Windows::Forms::Button^  btnSrvSynConnect;
private: System::Windows::Forms::TextBox^  txtSrvSynCom;



private: System::Windows::Forms::Button^  btnSrvSynRotate;



















private: System::ComponentModel::IContainer^  components;





	protected:

	protected:

	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->btnLazer = (gcnew System::Windows::Forms::Button());
			this->txtLzUzaklik = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lblLzFrekans = (gcnew System::Windows::Forms::Label());
			this->cbbLzHz = (gcnew System::Windows::Forms::ComboBox());
			this->lblLzUzaklik = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtStTargetX = (gcnew System::Windows::Forms::TextBox());
			this->txtStTargetY = (gcnew System::Windows::Forms::TextBox());
			this->txtStTargetZ = (gcnew System::Windows::Forms::TextBox());
			this->btnStCon = (gcnew System::Windows::Forms::Button());
			this->lblStVel = (gcnew System::Windows::Forms::Label());
			this->lblStPos = (gcnew System::Windows::Forms::Label());
			this->lblStStepSize = (gcnew System::Windows::Forms::Label());
			this->txtStVelX = (gcnew System::Windows::Forms::TextBox());
			this->txtStVelY = (gcnew System::Windows::Forms::TextBox());
			this->txtStPosX = (gcnew System::Windows::Forms::TextBox());
			this->txtStVelZ = (gcnew System::Windows::Forms::TextBox());
			this->txtStPosY = (gcnew System::Windows::Forms::TextBox());
			this->txtStStepSizeX = (gcnew System::Windows::Forms::TextBox());
			this->txtStPosZ = (gcnew System::Windows::Forms::TextBox());
			this->txtStStepSizeY = (gcnew System::Windows::Forms::TextBox());
			this->txtStStepSizeZ = (gcnew System::Windows::Forms::TextBox());
			this->btnStDecX = (gcnew System::Windows::Forms::Button());
			this->btnStLX = (gcnew System::Windows::Forms::Button());
			this->btnStDecY = (gcnew System::Windows::Forms::Button());
			this->btnStDecZ = (gcnew System::Windows::Forms::Button());
			this->btnStLY = (gcnew System::Windows::Forms::Button());
			this->btnStLZ = (gcnew System::Windows::Forms::Button());
			this->lblStZ = (gcnew System::Windows::Forms::Label());
			this->lblStY = (gcnew System::Windows::Forms::Label());
			this->lblStX = (gcnew System::Windows::Forms::Label());
			this->btnStIncZ = (gcnew System::Windows::Forms::Button());
			this->btnStIncY = (gcnew System::Windows::Forms::Button());
			this->btnStMZ = (gcnew System::Windows::Forms::Button());
			this->btnStIncX = (gcnew System::Windows::Forms::Button());
			this->btnStMY = (gcnew System::Windows::Forms::Button());
			this->btnStMX = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->lblSvDerece = (gcnew System::Windows::Forms::Label());
			this->lblSvRpm = (gcnew System::Windows::Forms::Label());
			this->lblSvCom = (gcnew System::Windows::Forms::Label());
			this->txtSvDerece = (gcnew System::Windows::Forms::TextBox());
			this->txtSvRpm = (gcnew System::Windows::Forms::TextBox());
			this->btnSvOrtala = (gcnew System::Windows::Forms::Button());
			this->btnServo = (gcnew System::Windows::Forms::Button());
			this->txtSvCom = (gcnew System::Windows::Forms::TextBox());
			this->btnSvDondur = (gcnew System::Windows::Forms::Button());
			this->timerStage = (gcnew System::Windows::Forms::Timer(this->components));
			this->kameraBaslat = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timerKamera = (gcnew System::Windows::Forms::Timer(this->components));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->anaMenu = (gcnew System::Windows::Forms::TabPage());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtSvDereceUst = (gcnew System::Windows::Forms::TextBox());
			this->txtSvRpmUst = (gcnew System::Windows::Forms::TextBox());
			this->btnSvOrtalaUst = (gcnew System::Windows::Forms::Button());
			this->btnServoUst = (gcnew System::Windows::Forms::Button());
			this->txtSvComUst = (gcnew System::Windows::Forms::TextBox());
			this->btnSvDondurUst = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtSrvSyncDeg = (gcnew System::Windows::Forms::TextBox());
			this->txtSrvSynRpm = (gcnew System::Windows::Forms::TextBox());
			this->btnSrvSynReset = (gcnew System::Windows::Forms::Button());
			this->btnSrvSynConnect = (gcnew System::Windows::Forms::Button());
			this->txtSrvSynCom = (gcnew System::Windows::Forms::TextBox());
			this->btnSrvSynRotate = (gcnew System::Windows::Forms::Button());
			this->kameraKapat = (gcnew System::Windows::Forms::Button());
			this->yardim = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->anaMenu->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->yardim->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnLazer
			// 
			this->btnLazer->Location = System::Drawing::Point(7, 22);
			this->btnLazer->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnLazer->Name = L"btnLazer";
			this->btnLazer->Size = System::Drawing::Size(200, 30);
			this->btnLazer->TabIndex = 0;
			this->btnLazer->Text = L"Lazer Baðlan";
			this->btnLazer->UseVisualStyleBackColor = true;
			this->btnLazer->Click += gcnew System::EventHandler(this, &Form1::btnLazer_Click);
			// 
			// txtLzUzaklik
			// 
			this->txtLzUzaklik->Location = System::Drawing::Point(125, 57);
			this->txtLzUzaklik->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtLzUzaklik->Multiline = true;
			this->txtLzUzaklik->Name = L"txtLzUzaklik";
			this->txtLzUzaklik->Size = System::Drawing::Size(80, 27);
			this->txtLzUzaklik->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->lblLzFrekans);
			this->groupBox1->Controls->Add(this->cbbLzHz);
			this->groupBox1->Controls->Add(this->lblLzUzaklik);
			this->groupBox1->Controls->Add(this->txtLzUzaklik);
			this->groupBox1->Controls->Add(this->btnLazer);
			this->groupBox1->Location = System::Drawing::Point(9, 7);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(216, 130);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Nokta Lazer";
			// 
			// lblLzFrekans
			// 
			this->lblLzFrekans->AutoSize = true;
			this->lblLzFrekans->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblLzFrekans->Location = System::Drawing::Point(12, 91);
			this->lblLzFrekans->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblLzFrekans->Name = L"lblLzFrekans";
			this->lblLzFrekans->Size = System::Drawing::Size(66, 18);
			this->lblLzFrekans->TabIndex = 24;
			this->lblLzFrekans->Text = L"Frekans:";
			// 
			// cbbLzHz
			// 
			this->cbbLzHz->Enabled = false;
			this->cbbLzHz->FormattingEnabled = true;
			this->cbbLzHz->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"49", L"30", L"20", L"10", L"5", L"2.5", L"1.5" });
			this->cbbLzHz->Location = System::Drawing::Point(92, 90);
			this->cbbLzHz->Margin = System::Windows::Forms::Padding(4);
			this->cbbLzHz->Name = L"cbbLzHz";
			this->cbbLzHz->Size = System::Drawing::Size(113, 24);
			this->cbbLzHz->TabIndex = 12;
			this->cbbLzHz->Text = L"Frekans Seç";
			this->cbbLzHz->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cbbLzHz_SelectedIndexChanged);
			// 
			// lblLzUzaklik
			// 
			this->lblLzUzaklik->AutoSize = true;
			this->lblLzUzaklik->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblLzUzaklik->Location = System::Drawing::Point(12, 60);
			this->lblLzUzaklik->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblLzUzaklik->Name = L"lblLzUzaklik";
			this->lblLzUzaklik->Size = System::Drawing::Size(97, 18);
			this->lblLzUzaklik->TabIndex = 12;
			this->lblLzUzaklik->Text = L"Uzaklýk (mm)";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->txtStTargetX);
			this->groupBox3->Controls->Add(this->txtStTargetY);
			this->groupBox3->Controls->Add(this->txtStTargetZ);
			this->groupBox3->Controls->Add(this->btnStCon);
			this->groupBox3->Controls->Add(this->lblStVel);
			this->groupBox3->Controls->Add(this->lblStPos);
			this->groupBox3->Controls->Add(this->lblStStepSize);
			this->groupBox3->Controls->Add(this->txtStVelX);
			this->groupBox3->Controls->Add(this->txtStVelY);
			this->groupBox3->Controls->Add(this->txtStPosX);
			this->groupBox3->Controls->Add(this->txtStVelZ);
			this->groupBox3->Controls->Add(this->txtStPosY);
			this->groupBox3->Controls->Add(this->txtStStepSizeX);
			this->groupBox3->Controls->Add(this->txtStPosZ);
			this->groupBox3->Controls->Add(this->txtStStepSizeY);
			this->groupBox3->Controls->Add(this->txtStStepSizeZ);
			this->groupBox3->Controls->Add(this->btnStDecX);
			this->groupBox3->Controls->Add(this->btnStLX);
			this->groupBox3->Controls->Add(this->btnStDecY);
			this->groupBox3->Controls->Add(this->btnStDecZ);
			this->groupBox3->Controls->Add(this->btnStLY);
			this->groupBox3->Controls->Add(this->btnStLZ);
			this->groupBox3->Controls->Add(this->lblStZ);
			this->groupBox3->Controls->Add(this->lblStY);
			this->groupBox3->Controls->Add(this->lblStX);
			this->groupBox3->Controls->Add(this->btnStIncZ);
			this->groupBox3->Controls->Add(this->btnStIncY);
			this->groupBox3->Controls->Add(this->btnStMZ);
			this->groupBox3->Controls->Add(this->btnStIncX);
			this->groupBox3->Controls->Add(this->btnStMY);
			this->groupBox3->Controls->Add(this->btnStMX);
			this->groupBox3->Location = System::Drawing::Point(972, 7);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4);
			this->groupBox3->Size = System::Drawing::Size(643, 174);
			this->groupBox3->TabIndex = 13;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Stage";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(575, 50);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 31;
			this->label1->Text = L"Hedef";
			// 
			// txtStTargetX
			// 
			this->txtStTargetX->Location = System::Drawing::Point(540, 69);
			this->txtStTargetX->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStTargetX->Multiline = true;
			this->txtStTargetX->Name = L"txtStTargetX";
			this->txtStTargetX->ReadOnly = true;
			this->txtStTargetX->Size = System::Drawing::Size(93, 26);
			this->txtStTargetX->TabIndex = 28;
			this->txtStTargetX->Text = L"18";
			// 
			// txtStTargetY
			// 
			this->txtStTargetY->Location = System::Drawing::Point(540, 102);
			this->txtStTargetY->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStTargetY->Multiline = true;
			this->txtStTargetY->Name = L"txtStTargetY";
			this->txtStTargetY->ReadOnly = true;
			this->txtStTargetY->Size = System::Drawing::Size(93, 26);
			this->txtStTargetY->TabIndex = 29;
			this->txtStTargetY->Text = L"5";
			// 
			// txtStTargetZ
			// 
			this->txtStTargetZ->Location = System::Drawing::Point(540, 137);
			this->txtStTargetZ->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStTargetZ->Multiline = true;
			this->txtStTargetZ->Name = L"txtStTargetZ";
			this->txtStTargetZ->ReadOnly = true;
			this->txtStTargetZ->Size = System::Drawing::Size(93, 26);
			this->txtStTargetZ->TabIndex = 30;
			this->txtStTargetZ->Text = L"9";
			// 
			// btnStCon
			// 
			this->btnStCon->Location = System::Drawing::Point(381, 16);
			this->btnStCon->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnStCon->Name = L"btnStCon";
			this->btnStCon->Size = System::Drawing::Size(252, 30);
			this->btnStCon->TabIndex = 13;
			this->btnStCon->Text = L"Stage Baðlan";
			this->btnStCon->UseVisualStyleBackColor = true;
			this->btnStCon->Click += gcnew System::EventHandler(this, &Form1::btnStCon_Click);
			// 
			// lblStVel
			// 
			this->lblStVel->AutoSize = true;
			this->lblStVel->Location = System::Drawing::Point(471, 52);
			this->lblStVel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblStVel->Name = L"lblStVel";
			this->lblStVel->Size = System::Drawing::Size(28, 17);
			this->lblStVel->TabIndex = 27;
			this->lblStVel->Text = L"Hýz";
			// 
			// lblStPos
			// 
			this->lblStPos->AutoSize = true;
			this->lblStPos->Location = System::Drawing::Point(172, 52);
			this->lblStPos->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblStPos->Name = L"lblStPos";
			this->lblStPos->Size = System::Drawing::Size(65, 17);
			this->lblStPos->TabIndex = 26;
			this->lblStPos->Text = L"Pozisyon";
			// 
			// lblStStepSize
			// 
			this->lblStStepSize->AutoSize = true;
			this->lblStStepSize->Location = System::Drawing::Point(347, 50);
			this->lblStStepSize->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblStStepSize->Name = L"lblStStepSize";
			this->lblStStepSize->Size = System::Drawing::Size(87, 17);
			this->lblStStepSize->TabIndex = 25;
			this->lblStStepSize->Text = L"Adým Boyutu";
			// 
			// txtStVelX
			// 
			this->txtStVelX->Location = System::Drawing::Point(440, 69);
			this->txtStVelX->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStVelX->Multiline = true;
			this->txtStVelX->Name = L"txtStVelX";
			this->txtStVelX->Size = System::Drawing::Size(93, 26);
			this->txtStVelX->TabIndex = 20;
			this->txtStVelX->Text = L"2.0";
			// 
			// txtStVelY
			// 
			this->txtStVelY->Location = System::Drawing::Point(440, 102);
			this->txtStVelY->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStVelY->Multiline = true;
			this->txtStVelY->Name = L"txtStVelY";
			this->txtStVelY->Size = System::Drawing::Size(93, 26);
			this->txtStVelY->TabIndex = 21;
			this->txtStVelY->Text = L"2";
			// 
			// txtStPosX
			// 
			this->txtStPosX->Location = System::Drawing::Point(157, 69);
			this->txtStPosX->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStPosX->Multiline = true;
			this->txtStPosX->Name = L"txtStPosX";
			this->txtStPosX->ReadOnly = true;
			this->txtStPosX->Size = System::Drawing::Size(93, 26);
			this->txtStPosX->TabIndex = 17;
			this->txtStPosX->Text = L"18";
			// 
			// txtStVelZ
			// 
			this->txtStVelZ->Location = System::Drawing::Point(440, 137);
			this->txtStVelZ->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStVelZ->Multiline = true;
			this->txtStVelZ->Name = L"txtStVelZ";
			this->txtStVelZ->Size = System::Drawing::Size(93, 26);
			this->txtStVelZ->TabIndex = 22;
			this->txtStVelZ->Text = L"2";
			// 
			// txtStPosY
			// 
			this->txtStPosY->Location = System::Drawing::Point(157, 102);
			this->txtStPosY->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStPosY->Multiline = true;
			this->txtStPosY->Name = L"txtStPosY";
			this->txtStPosY->ReadOnly = true;
			this->txtStPosY->Size = System::Drawing::Size(93, 26);
			this->txtStPosY->TabIndex = 18;
			this->txtStPosY->Text = L"5";
			// 
			// txtStStepSizeX
			// 
			this->txtStStepSizeX->Location = System::Drawing::Point(340, 69);
			this->txtStStepSizeX->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStStepSizeX->Multiline = true;
			this->txtStStepSizeX->Name = L"txtStStepSizeX";
			this->txtStStepSizeX->Size = System::Drawing::Size(93, 26);
			this->txtStStepSizeX->TabIndex = 17;
			this->txtStStepSizeX->Text = L"2";
			// 
			// txtStPosZ
			// 
			this->txtStPosZ->Location = System::Drawing::Point(157, 137);
			this->txtStPosZ->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStPosZ->Multiline = true;
			this->txtStPosZ->Name = L"txtStPosZ";
			this->txtStPosZ->ReadOnly = true;
			this->txtStPosZ->Size = System::Drawing::Size(93, 26);
			this->txtStPosZ->TabIndex = 19;
			this->txtStPosZ->Text = L"9";
			// 
			// txtStStepSizeY
			// 
			this->txtStStepSizeY->Location = System::Drawing::Point(340, 102);
			this->txtStStepSizeY->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStStepSizeY->Multiline = true;
			this->txtStStepSizeY->Name = L"txtStStepSizeY";
			this->txtStStepSizeY->Size = System::Drawing::Size(93, 26);
			this->txtStStepSizeY->TabIndex = 18;
			this->txtStStepSizeY->Text = L"2";
			// 
			// txtStStepSizeZ
			// 
			this->txtStStepSizeZ->Location = System::Drawing::Point(340, 137);
			this->txtStStepSizeZ->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtStStepSizeZ->Multiline = true;
			this->txtStStepSizeZ->Name = L"txtStStepSizeZ";
			this->txtStStepSizeZ->Size = System::Drawing::Size(93, 26);
			this->txtStStepSizeZ->TabIndex = 19;
			this->txtStStepSizeZ->Text = L"2";
			// 
			// btnStDecX
			// 
			this->btnStDecX->Location = System::Drawing::Point(117, 69);
			this->btnStDecX->Margin = System::Windows::Forms::Padding(4);
			this->btnStDecX->Name = L"btnStDecX";
			this->btnStDecX->Size = System::Drawing::Size(33, 27);
			this->btnStDecX->TabIndex = 15;
			this->btnStDecX->Text = L"<";
			this->btnStDecX->UseVisualStyleBackColor = true;
			this->btnStDecX->Click += gcnew System::EventHandler(this, &Form1::btnStDecX_Click);
			// 
			// btnStLX
			// 
			this->btnStLX->Location = System::Drawing::Point(76, 69);
			this->btnStLX->Margin = System::Windows::Forms::Padding(4);
			this->btnStLX->Name = L"btnStLX";
			this->btnStLX->Size = System::Drawing::Size(33, 27);
			this->btnStLX->TabIndex = 14;
			this->btnStLX->Text = L"|<";
			this->btnStLX->UseVisualStyleBackColor = true;
			this->btnStLX->Click += gcnew System::EventHandler(this, &Form1::btnStLX_Click);
			// 
			// btnStDecY
			// 
			this->btnStDecY->Location = System::Drawing::Point(117, 103);
			this->btnStDecY->Margin = System::Windows::Forms::Padding(4);
			this->btnStDecY->Name = L"btnStDecY";
			this->btnStDecY->Size = System::Drawing::Size(33, 27);
			this->btnStDecY->TabIndex = 17;
			this->btnStDecY->Text = L"<";
			this->btnStDecY->UseVisualStyleBackColor = true;
			this->btnStDecY->Click += gcnew System::EventHandler(this, &Form1::btnStDecY_Click);
			// 
			// btnStDecZ
			// 
			this->btnStDecZ->Location = System::Drawing::Point(117, 138);
			this->btnStDecZ->Margin = System::Windows::Forms::Padding(4);
			this->btnStDecZ->Name = L"btnStDecZ";
			this->btnStDecZ->Size = System::Drawing::Size(33, 27);
			this->btnStDecZ->TabIndex = 19;
			this->btnStDecZ->Text = L"<";
			this->btnStDecZ->UseVisualStyleBackColor = true;
			this->btnStDecZ->Click += gcnew System::EventHandler(this, &Form1::btnStDecZ_Click);
			// 
			// btnStLY
			// 
			this->btnStLY->Location = System::Drawing::Point(76, 103);
			this->btnStLY->Margin = System::Windows::Forms::Padding(4);
			this->btnStLY->Name = L"btnStLY";
			this->btnStLY->Size = System::Drawing::Size(33, 27);
			this->btnStLY->TabIndex = 16;
			this->btnStLY->Text = L"|<";
			this->btnStLY->UseVisualStyleBackColor = true;
			this->btnStLY->Click += gcnew System::EventHandler(this, &Form1::btnStLY_Click);
			// 
			// btnStLZ
			// 
			this->btnStLZ->Location = System::Drawing::Point(76, 138);
			this->btnStLZ->Margin = System::Windows::Forms::Padding(4);
			this->btnStLZ->Name = L"btnStLZ";
			this->btnStLZ->Size = System::Drawing::Size(33, 27);
			this->btnStLZ->TabIndex = 18;
			this->btnStLZ->Text = L"|<";
			this->btnStLZ->UseVisualStyleBackColor = true;
			this->btnStLZ->Click += gcnew System::EventHandler(this, &Form1::btnStLZ_Click);
			// 
			// lblStZ
			// 
			this->lblStZ->AutoSize = true;
			this->lblStZ->Location = System::Drawing::Point(12, 142);
			this->lblStZ->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblStZ->Name = L"lblStZ";
			this->lblStZ->Size = System::Drawing::Size(58, 17);
			this->lblStZ->TabIndex = 19;
			this->lblStZ->Text = L"Stage Z";
			// 
			// lblStY
			// 
			this->lblStY->AutoSize = true;
			this->lblStY->Location = System::Drawing::Point(12, 110);
			this->lblStY->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblStY->Name = L"lblStY";
			this->lblStY->Size = System::Drawing::Size(58, 17);
			this->lblStY->TabIndex = 20;
			this->lblStY->Text = L"Stage Y";
			// 
			// lblStX
			// 
			this->lblStX->AutoSize = true;
			this->lblStX->Location = System::Drawing::Point(12, 78);
			this->lblStX->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblStX->Name = L"lblStX";
			this->lblStX->Size = System::Drawing::Size(58, 17);
			this->lblStX->TabIndex = 21;
			this->lblStX->Text = L"Stage X";
			// 
			// btnStIncZ
			// 
			this->btnStIncZ->Location = System::Drawing::Point(259, 138);
			this->btnStIncZ->Margin = System::Windows::Forms::Padding(4);
			this->btnStIncZ->Name = L"btnStIncZ";
			this->btnStIncZ->Size = System::Drawing::Size(33, 27);
			this->btnStIncZ->TabIndex = 16;
			this->btnStIncZ->Text = L">";
			this->btnStIncZ->UseVisualStyleBackColor = true;
			this->btnStIncZ->Click += gcnew System::EventHandler(this, &Form1::btnStIncZ_Click);
			// 
			// btnStIncY
			// 
			this->btnStIncY->Location = System::Drawing::Point(259, 103);
			this->btnStIncY->Margin = System::Windows::Forms::Padding(4);
			this->btnStIncY->Name = L"btnStIncY";
			this->btnStIncY->Size = System::Drawing::Size(33, 27);
			this->btnStIncY->TabIndex = 23;
			this->btnStIncY->Text = L">";
			this->btnStIncY->UseVisualStyleBackColor = true;
			this->btnStIncY->Click += gcnew System::EventHandler(this, &Form1::btnStIncY_Click);
			// 
			// btnStMZ
			// 
			this->btnStMZ->Location = System::Drawing::Point(300, 138);
			this->btnStMZ->Margin = System::Windows::Forms::Padding(4);
			this->btnStMZ->Name = L"btnStMZ";
			this->btnStMZ->Size = System::Drawing::Size(33, 27);
			this->btnStMZ->TabIndex = 15;
			this->btnStMZ->Text = L">|";
			this->btnStMZ->UseVisualStyleBackColor = true;
			this->btnStMZ->Click += gcnew System::EventHandler(this, &Form1::btnStMZ_Click);
			// 
			// btnStIncX
			// 
			this->btnStIncX->Location = System::Drawing::Point(259, 69);
			this->btnStIncX->Margin = System::Windows::Forms::Padding(4);
			this->btnStIncX->Name = L"btnStIncX";
			this->btnStIncX->Size = System::Drawing::Size(33, 27);
			this->btnStIncX->TabIndex = 20;
			this->btnStIncX->Text = L">";
			this->btnStIncX->UseVisualStyleBackColor = true;
			this->btnStIncX->Click += gcnew System::EventHandler(this, &Form1::btnStIncX_Click);
			// 
			// btnStMY
			// 
			this->btnStMY->Location = System::Drawing::Point(300, 103);
			this->btnStMY->Margin = System::Windows::Forms::Padding(4);
			this->btnStMY->Name = L"btnStMY";
			this->btnStMY->Size = System::Drawing::Size(33, 27);
			this->btnStMY->TabIndex = 22;
			this->btnStMY->Text = L">|";
			this->btnStMY->UseVisualStyleBackColor = true;
			this->btnStMY->Click += gcnew System::EventHandler(this, &Form1::btnStMY_Click);
			// 
			// btnStMX
			// 
			this->btnStMX->Location = System::Drawing::Point(300, 69);
			this->btnStMX->Margin = System::Windows::Forms::Padding(4);
			this->btnStMX->Name = L"btnStMX";
			this->btnStMX->Size = System::Drawing::Size(33, 27);
			this->btnStMX->TabIndex = 21;
			this->btnStMX->Text = L">|";
			this->btnStMX->UseVisualStyleBackColor = true;
			this->btnStMX->Click += gcnew System::EventHandler(this, &Form1::btnStMX_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->lblSvDerece);
			this->groupBox4->Controls->Add(this->lblSvRpm);
			this->groupBox4->Controls->Add(this->lblSvCom);
			this->groupBox4->Controls->Add(this->txtSvDerece);
			this->groupBox4->Controls->Add(this->txtSvRpm);
			this->groupBox4->Controls->Add(this->btnSvOrtala);
			this->groupBox4->Controls->Add(this->btnServo);
			this->groupBox4->Controls->Add(this->txtSvCom);
			this->groupBox4->Controls->Add(this->btnSvDondur);
			this->groupBox4->Location = System::Drawing::Point(7, 2);
			this->groupBox4->Margin = System::Windows::Forms::Padding(4);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(4);
			this->groupBox4->Size = System::Drawing::Size(344, 130);
			this->groupBox4->TabIndex = 14;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Alt Servo";
			// 
			// lblSvDerece
			// 
			this->lblSvDerece->AutoSize = true;
			this->lblSvDerece->Location = System::Drawing::Point(197, 64);
			this->lblSvDerece->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblSvDerece->Name = L"lblSvDerece";
			this->lblSvDerece->Size = System::Drawing::Size(125, 17);
			this->lblSvDerece->TabIndex = 21;
			this->lblSvDerece->Text = L"Derece (-20 / +20)";
			this->lblSvDerece->Click += gcnew System::EventHandler(this, &Form1::lblSvDerece_Click);
			// 
			// lblSvRpm
			// 
			this->lblSvRpm->AutoSize = true;
			this->lblSvRpm->Location = System::Drawing::Point(97, 64);
			this->lblSvRpm->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblSvRpm->Name = L"lblSvRpm";
			this->lblSvRpm->Size = System::Drawing::Size(83, 17);
			this->lblSvRpm->TabIndex = 22;
			this->lblSvRpm->Text = L"rpm (0-115)";
			// 
			// lblSvCom
			// 
			this->lblSvCom->AutoSize = true;
			this->lblSvCom->Location = System::Drawing::Point(97, 18);
			this->lblSvCom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblSvCom->Name = L"lblSvCom";
			this->lblSvCom->Size = System::Drawing::Size(77, 17);
			this->lblSvCom->TabIndex = 23;
			this->lblSvCom->Text = L"COM Portu";
			// 
			// txtSvDerece
			// 
			this->txtSvDerece->Enabled = false;
			this->txtSvDerece->Location = System::Drawing::Point(212, 88);
			this->txtSvDerece->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtSvDerece->Multiline = true;
			this->txtSvDerece->Name = L"txtSvDerece";
			this->txtSvDerece->Size = System::Drawing::Size(93, 27);
			this->txtSvDerece->TabIndex = 21;
			// 
			// txtSvRpm
			// 
			this->txtSvRpm->Enabled = false;
			this->txtSvRpm->Location = System::Drawing::Point(99, 88);
			this->txtSvRpm->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtSvRpm->Multiline = true;
			this->txtSvRpm->Name = L"txtSvRpm";
			this->txtSvRpm->Size = System::Drawing::Size(93, 27);
			this->txtSvRpm->TabIndex = 22;
			// 
			// btnSvOrtala
			// 
			this->btnSvOrtala->Enabled = false;
			this->btnSvOrtala->Location = System::Drawing::Point(215, 8);
			this->btnSvOrtala->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSvOrtala->Name = L"btnSvOrtala";
			this->btnSvOrtala->Size = System::Drawing::Size(95, 47);
			this->btnSvOrtala->TabIndex = 17;
			this->btnSvOrtala->Text = L"Ortala";
			this->btnSvOrtala->UseVisualStyleBackColor = true;
			this->btnSvOrtala->Click += gcnew System::EventHandler(this, &Form1::btnSvOrtala_Click);
			// 
			// btnServo
			// 
			this->btnServo->Location = System::Drawing::Point(7, 16);
			this->btnServo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnServo->Name = L"btnServo";
			this->btnServo->Size = System::Drawing::Size(83, 47);
			this->btnServo->TabIndex = 15;
			this->btnServo->Text = L"Servo Baðlan";
			this->btnServo->UseVisualStyleBackColor = true;
			this->btnServo->Click += gcnew System::EventHandler(this, &Form1::btnServo_Click);
			// 
			// txtSvCom
			// 
			this->txtSvCom->Location = System::Drawing::Point(96, 37);
			this->txtSvCom->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtSvCom->Multiline = true;
			this->txtSvCom->Name = L"txtSvCom";
			this->txtSvCom->Size = System::Drawing::Size(93, 26);
			this->txtSvCom->TabIndex = 17;
			// 
			// btnSvDondur
			// 
			this->btnSvDondur->Enabled = false;
			this->btnSvDondur->Location = System::Drawing::Point(7, 67);
			this->btnSvDondur->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSvDondur->Name = L"btnSvDondur";
			this->btnSvDondur->Size = System::Drawing::Size(83, 50);
			this->btnSvDondur->TabIndex = 16;
			this->btnSvDondur->Text = L"Döndür";
			this->btnSvDondur->UseVisualStyleBackColor = true;
			this->btnSvDondur->Click += gcnew System::EventHandler(this, &Form1::btnSvDondur_Click);
			// 
			// timerStage
			// 
			this->timerStage->Interval = 50;
			this->timerStage->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// kameraBaslat
			// 
			this->kameraBaslat->Location = System::Drawing::Point(10, 175);
			this->kameraBaslat->Margin = System::Windows::Forms::Padding(4);
			this->kameraBaslat->Name = L"kameraBaslat";
			this->kameraBaslat->Size = System::Drawing::Size(216, 36);
			this->kameraBaslat->TabIndex = 15;
			this->kameraBaslat->Text = L"Kamera Baþlat";
			this->kameraBaslat->UseVisualStyleBackColor = true;
			this->kameraBaslat->Click += gcnew System::EventHandler(this, &Form1::kameraBaslat_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(9, 219);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1631, 754);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 16;
			this->pictureBox1->TabStop = false;
			// 
			// timerKamera
			// 
			this->timerKamera->Interval = 50;
			this->timerKamera->Tick += gcnew System::EventHandler(this, &Form1::timerKamera_Tick);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->anaMenu);
			this->tabControl1->Controls->Add(this->yardim);
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1656, 1006);
			this->tabControl1->TabIndex = 17;
			// 
			// anaMenu
			// 
			this->anaMenu->Controls->Add(this->tabControl2);
			this->anaMenu->Controls->Add(this->kameraKapat);
			this->anaMenu->Controls->Add(this->groupBox1);
			this->anaMenu->Controls->Add(this->pictureBox1);
			this->anaMenu->Controls->Add(this->groupBox3);
			this->anaMenu->Controls->Add(this->kameraBaslat);
			this->anaMenu->Location = System::Drawing::Point(4, 25);
			this->anaMenu->Margin = System::Windows::Forms::Padding(4);
			this->anaMenu->Name = L"anaMenu";
			this->anaMenu->Padding = System::Windows::Forms::Padding(4);
			this->anaMenu->Size = System::Drawing::Size(1648, 977);
			this->anaMenu->TabIndex = 0;
			this->anaMenu->Text = L"Ana Menü";
			this->anaMenu->UseVisualStyleBackColor = true;
			this->anaMenu->Click += gcnew System::EventHandler(this, &Form1::anaMenu_Click);
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->tabPage1);
			this->tabControl2->Controls->Add(this->tabPage2);
			this->tabControl2->Location = System::Drawing::Point(233, 7);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(732, 165);
			this->tabControl2->TabIndex = 25;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox4);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(724, 136);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Ayrý Kontrol";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &Form1::tabPage1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->txtSvDereceUst);
			this->groupBox2->Controls->Add(this->txtSvRpmUst);
			this->groupBox2->Controls->Add(this->btnSvOrtalaUst);
			this->groupBox2->Controls->Add(this->btnServoUst);
			this->groupBox2->Controls->Add(this->txtSvComUst);
			this->groupBox2->Controls->Add(this->btnSvDondurUst);
			this->groupBox2->Location = System::Drawing::Point(359, 2);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(344, 130);
			this->groupBox2->TabIndex = 24;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Üst Servo";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(195, 63);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 17);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Derece (-135 / +135)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(97, 64);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 17);
			this->label3->TabIndex = 22;
			this->label3->Text = L"rpm (0-115)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(97, 17);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(77, 17);
			this->label4->TabIndex = 23;
			this->label4->Text = L"COM Portu";
			// 
			// txtSvDereceUst
			// 
			this->txtSvDereceUst->Enabled = false;
			this->txtSvDereceUst->Location = System::Drawing::Point(215, 84);
			this->txtSvDereceUst->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtSvDereceUst->Multiline = true;
			this->txtSvDereceUst->Name = L"txtSvDereceUst";
			this->txtSvDereceUst->Size = System::Drawing::Size(93, 27);
			this->txtSvDereceUst->TabIndex = 21;
			// 
			// txtSvRpmUst
			// 
			this->txtSvRpmUst->Enabled = false;
			this->txtSvRpmUst->Location = System::Drawing::Point(95, 84);
			this->txtSvRpmUst->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtSvRpmUst->Multiline = true;
			this->txtSvRpmUst->Name = L"txtSvRpmUst";
			this->txtSvRpmUst->Size = System::Drawing::Size(93, 27);
			this->txtSvRpmUst->TabIndex = 22;
			// 
			// btnSvOrtalaUst
			// 
			this->btnSvOrtalaUst->Enabled = false;
			this->btnSvOrtalaUst->Location = System::Drawing::Point(215, 14);
			this->btnSvOrtalaUst->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSvOrtalaUst->Name = L"btnSvOrtalaUst";
			this->btnSvOrtalaUst->Size = System::Drawing::Size(95, 47);
			this->btnSvOrtalaUst->TabIndex = 17;
			this->btnSvOrtalaUst->Text = L"Ortala";
			this->btnSvOrtalaUst->UseVisualStyleBackColor = true;
			this->btnSvOrtalaUst->Click += gcnew System::EventHandler(this, &Form1::btnSvOrtalaUst_Click);
			// 
			// btnServoUst
			// 
			this->btnServoUst->Location = System::Drawing::Point(7, 17);
			this->btnServoUst->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnServoUst->Name = L"btnServoUst";
			this->btnServoUst->Size = System::Drawing::Size(83, 47);
			this->btnServoUst->TabIndex = 15;
			this->btnServoUst->Text = L"Servo Baðlan";
			this->btnServoUst->UseVisualStyleBackColor = true;
			this->btnServoUst->Click += gcnew System::EventHandler(this, &Form1::btnServoUst_Click);
			// 
			// txtSvComUst
			// 
			this->txtSvComUst->Location = System::Drawing::Point(95, 34);
			this->txtSvComUst->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtSvComUst->Multiline = true;
			this->txtSvComUst->Name = L"txtSvComUst";
			this->txtSvComUst->Size = System::Drawing::Size(93, 26);
			this->txtSvComUst->TabIndex = 17;
			// 
			// btnSvDondurUst
			// 
			this->btnSvDondurUst->Enabled = false;
			this->btnSvDondurUst->Location = System::Drawing::Point(7, 68);
			this->btnSvDondurUst->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSvDondurUst->Name = L"btnSvDondurUst";
			this->btnSvDondurUst->Size = System::Drawing::Size(83, 50);
			this->btnSvDondurUst->TabIndex = 16;
			this->btnSvDondurUst->Text = L"Döndür";
			this->btnSvDondurUst->UseVisualStyleBackColor = true;
			this->btnSvDondurUst->Click += gcnew System::EventHandler(this, &Form1::btnSvDondurUst_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox5);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(724, 136);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Senkron Kontrol";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label5);
			this->groupBox5->Controls->Add(this->label6);
			this->groupBox5->Controls->Add(this->label7);
			this->groupBox5->Controls->Add(this->txtSrvSyncDeg);
			this->groupBox5->Controls->Add(this->txtSrvSynRpm);
			this->groupBox5->Controls->Add(this->btnSrvSynReset);
			this->groupBox5->Controls->Add(this->btnSrvSynConnect);
			this->groupBox5->Controls->Add(this->txtSrvSynCom);
			this->groupBox5->Controls->Add(this->btnSrvSynRotate);
			this->groupBox5->Location = System::Drawing::Point(25, 6);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(338, 124);
			this->groupBox5->TabIndex = 0;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Senkron Kontrol";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(202, 64);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(125, 17);
			this->label5->TabIndex = 28;
			this->label5->Text = L"Derece (-20 / +20)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(102, 64);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(83, 17);
			this->label6->TabIndex = 30;
			this->label6->Text = L"rpm (0-115)";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(102, 18);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(77, 17);
			this->label7->TabIndex = 32;
			this->label7->Text = L"COM Portu";
			// 
			// txtSrvSyncDeg
			// 
			this->txtSrvSyncDeg->Enabled = false;
			this->txtSrvSyncDeg->Location = System::Drawing::Point(217, 88);
			this->txtSrvSyncDeg->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtSrvSyncDeg->Multiline = true;
			this->txtSrvSyncDeg->Name = L"txtSrvSyncDeg";
			this->txtSrvSyncDeg->Size = System::Drawing::Size(93, 27);
			this->txtSrvSyncDeg->TabIndex = 29;
			// 
			// txtSrvSynRpm
			// 
			this->txtSrvSynRpm->Enabled = false;
			this->txtSrvSynRpm->Location = System::Drawing::Point(104, 88);
			this->txtSrvSynRpm->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtSrvSynRpm->Multiline = true;
			this->txtSrvSynRpm->Name = L"txtSrvSynRpm";
			this->txtSrvSynRpm->Size = System::Drawing::Size(93, 27);
			this->txtSrvSynRpm->TabIndex = 31;
			// 
			// btnSrvSynReset
			// 
			this->btnSrvSynReset->Enabled = false;
			this->btnSrvSynReset->Location = System::Drawing::Point(217, 14);
			this->btnSrvSynReset->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSrvSynReset->Name = L"btnSrvSynReset";
			this->btnSrvSynReset->Size = System::Drawing::Size(95, 47);
			this->btnSrvSynReset->TabIndex = 26;
			this->btnSrvSynReset->Text = L"Ortala";
			this->btnSrvSynReset->UseVisualStyleBackColor = true;
			this->btnSrvSynReset->Click += gcnew System::EventHandler(this, &Form1::btnSrvSynReset_Click);
			// 
			// btnSrvSynConnect
			// 
			this->btnSrvSynConnect->Location = System::Drawing::Point(12, 16);
			this->btnSrvSynConnect->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSrvSynConnect->Name = L"btnSrvSynConnect";
			this->btnSrvSynConnect->Size = System::Drawing::Size(83, 47);
			this->btnSrvSynConnect->TabIndex = 24;
			this->btnSrvSynConnect->Text = L"Servo Baðlan";
			this->btnSrvSynConnect->UseVisualStyleBackColor = true;
			this->btnSrvSynConnect->Click += gcnew System::EventHandler(this, &Form1::btnSrvSynConnect_Click);
			// 
			// txtSrvSynCom
			// 
			this->txtSrvSynCom->Location = System::Drawing::Point(101, 37);
			this->txtSrvSynCom->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtSrvSynCom->Multiline = true;
			this->txtSrvSynCom->Name = L"txtSrvSynCom";
			this->txtSrvSynCom->Size = System::Drawing::Size(93, 26);
			this->txtSrvSynCom->TabIndex = 27;
			// 
			// btnSrvSynRotate
			// 
			this->btnSrvSynRotate->Enabled = false;
			this->btnSrvSynRotate->Location = System::Drawing::Point(12, 67);
			this->btnSrvSynRotate->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSrvSynRotate->Name = L"btnSrvSynRotate";
			this->btnSrvSynRotate->Size = System::Drawing::Size(83, 50);
			this->btnSrvSynRotate->TabIndex = 25;
			this->btnSrvSynRotate->Text = L"Döndür";
			this->btnSrvSynRotate->UseVisualStyleBackColor = true;
			this->btnSrvSynRotate->Click += gcnew System::EventHandler(this, &Form1::btnSrvSynRotate_Click);
			// 
			// kameraKapat
			// 
			this->kameraKapat->Location = System::Drawing::Point(233, 175);
			this->kameraKapat->Margin = System::Windows::Forms::Padding(4);
			this->kameraKapat->Name = L"kameraKapat";
			this->kameraKapat->Size = System::Drawing::Size(216, 36);
			this->kameraKapat->TabIndex = 17;
			this->kameraKapat->Text = L"Kamera Kapat";
			this->kameraKapat->UseVisualStyleBackColor = true;
			this->kameraKapat->Click += gcnew System::EventHandler(this, &Form1::kameraKapat_Click);
			// 
			// yardim
			// 
			this->yardim->Controls->Add(this->richTextBox1);
			this->yardim->Location = System::Drawing::Point(4, 25);
			this->yardim->Margin = System::Windows::Forms::Padding(4);
			this->yardim->Name = L"yardim";
			this->yardim->Padding = System::Windows::Forms::Padding(4);
			this->yardim->Size = System::Drawing::Size(1648, 977);
			this->yardim->TabIndex = 1;
			this->yardim->Text = L"Yardým";
			this->yardim->UseVisualStyleBackColor = true;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->richTextBox1->Location = System::Drawing::Point(11, 7);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(1217, 867);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = resources->GetString(L"richTextBox1.Text");
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox1_TextChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1664, 1008);
			this->Controls->Add(this->tabControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form1";
			this->Text = L"Mikro Kontrol";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->anaMenu->ResumeLayout(false);
			this->tabControl2->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->yardim->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void btnStCon_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (!timerStage->Enabled)
	{
		timerStage->Start();
	}

	btnSt_click_event(btnStCon, txtStPosX, txtStPosY, txtStPosZ);
	
}
private: System::Void btnLazer_Click(System::Object^  sender, System::EventArgs^  e) 
{
	btnLz_click_event(btnLazer, txtLzUzaklik, cbbLzHz);
}
private: System::Void cbbLzHz_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	cbbLz_indexchange_event(cbbLzHz, lblLzFrekans);
}

private: System::Void btnStMX_Click(System::Object^  sender, System::EventArgs^  e) {
	UpdatePositionsStepSizeandVel(txtStVelX, txtStStepSizeX, "1", txtStPosX, txtStTargetX);

	FullRight("1");

	
}
private: System::Void btnStMY_Click(System::Object^  sender, System::EventArgs^  e) {
	UpdatePositionsStepSizeandVel(txtStVelY, txtStStepSizeY, "2", txtStPosY, txtStTargetY);

	FullRight("2");

	
}
private: System::Void btnStMZ_Click(System::Object^  sender, System::EventArgs^  e) {
	UpdatePositionsStepSizeandVel(txtStVelZ, txtStStepSizeZ, "3", txtStPosZ, txtStTargetZ);

	FullRight("3");

	
}
private: System::Void btnStLX_Click(System::Object^  sender, System::EventArgs^  e) {
	UpdatePositionsStepSizeandVel(txtStVelX, txtStStepSizeX, "1", txtStPosX, txtStTargetX);
	
	FullLeft("1");

	
}
private: System::Void btnStLY_Click(System::Object^  sender, System::EventArgs^  e) {
	UpdatePositionsStepSizeandVel(txtStVelY, txtStStepSizeY, "2", txtStPosY, txtStTargetY);
	
	FullLeft("2");

	
}
private: System::Void btnStLZ_Click(System::Object^  sender, System::EventArgs^  e) {
	UpdatePositionsStepSizeandVel(txtStVelZ, txtStStepSizeZ, "3", txtStPosZ, txtStTargetZ);
	
	FullLeft("3");

	
}
private: System::Void btnStIncX_Click(System::Object^  sender, System::EventArgs^  e) {
	UpdatePositionsStepSizeandVel(txtStVelX, txtStStepSizeX, "1", txtStPosX, txtStTargetX);
	
	StepRight("1");

	
}
private: System::Void btnStIncY_Click(System::Object^  sender, System::EventArgs^  e) {
	UpdatePositionsStepSizeandVel(txtStVelY, txtStStepSizeY, "2", txtStPosY, txtStTargetY);
	
	StepRight("2");

	
}
private: System::Void btnStIncZ_Click(System::Object^  sender, System::EventArgs^  e) {
	UpdatePositionsStepSizeandVel(txtStVelZ, txtStStepSizeZ, "3", txtStPosZ, txtStTargetZ);
	
	StepRight("3");

	
}
private: System::Void btnStDecX_Click(System::Object^  sender, System::EventArgs^  e) {
	UpdatePositionsStepSizeandVel(txtStVelX, txtStStepSizeX, "1", txtStPosX, txtStTargetX);
	
	StepLeft("1");
}
private: System::Void btnStDecY_Click(System::Object^  sender, System::EventArgs^  e) {
	UpdatePositionsStepSizeandVel(txtStVelY, txtStStepSizeY, "2", txtStPosY, txtStTargetY);
	
	StepLeft("2");
}
private: System::Void btnStDecZ_Click(System::Object^  sender, System::EventArgs^  e) {
	UpdatePositionsStepSizeandVel(txtStVelZ, txtStStepSizeZ, "3", txtStPosZ, txtStTargetZ);
	
	StepLeft("3");	
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	UpdatePositionsStepSizeandVel(txtStVelX, txtStStepSizeX, "1", txtStPosX, txtStTargetX);
	UpdatePositionsStepSizeandVel(txtStVelY, txtStStepSizeY, "2", txtStPosY, txtStTargetY);
	UpdatePositionsStepSizeandVel(txtStVelZ, txtStStepSizeZ, "3", txtStPosZ, txtStTargetZ);
}
private: System::Void kameraBaslat_Click(System::Object^  sender, System::EventArgs^  e) {
	camera.Connect(0);

	camera.GetCameraInfo(&camInfo);

	camera.StartCapture();
	
	if (!timerKamera->Enabled)
	{
		timerKamera->Start();
	}	
}
private: System::Void timerKamera_Tick(System::Object^  sender, System::EventArgs^  e) {
	camera.RetrieveBuffer(&rawImage);	

	rawImage.Convert(FlyCapture2::PIXEL_FORMAT_BGR, &rgbImage);
	
	unsigned int rowBytes = rgbImage.GetReceivedDataSize() / rgbImage.GetRows();
	image = cv::Mat(rgbImage.GetRows(), rgbImage.GetCols(), CV_8UC3, rgbImage.GetData(), rowBytes);

	Bitmap^ test = gcnew Bitmap(image.rows, image.cols, image.step1(), System::Drawing::Imaging::PixelFormat::Format24bppRgb, IntPtr(image.data));

	pictureBox1->Image = test;
	pictureBox1->Refresh();
}
private: System::Void kameraKapat_Click(System::Object^  sender, System::EventArgs^  e) {
	camera.StopCapture();

	camera.Disconnect();

	delete pictureBox1->Image;
	pictureBox1->Image = nullptr;

	timerKamera->Stop();	
}
private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	timerKamera->Stop();
	timerStage->Stop();
	lazerKapat();
	//servoKapat();     fonk yazýlacak hazýr olduðu zaman
	//Stage otomatik kapanýyor
}
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	csvData.close();
}

private: System::Void lblSvDerece_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void anaMenu_Click(System::Object^  sender, System::EventArgs^  e) {
}




private: System::Void btnServo_Click(System::Object^  sender, System::EventArgs^  e) {
	Form1::btnServo_click_event(btnServo, txtSvRpm, txtSvDerece, btnSvDondur, btnSvOrtala, txtSvCom,txtSvRpmUst,ALT_SERVO_STR_ID);
}
private: System::Void btnSvOrtala_Click(System::Object^  sender, System::EventArgs^  e) {
	Form1::btnSvOrtala_click_event(btnSvOrtala,ALT_SERVO_STR_ID);
}
private: System::Void btnSvDondur_Click(System::Object^  sender, System::EventArgs^  e) {
	Form1::btnSvDondur_click_event(btnSvDondur, txtSvRpm, txtSvDerece,ALT_SERVO_STR_ID);
}
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void btnServoUst_Click(System::Object^  sender, System::EventArgs^  e) {
	btnServo_click_event(btnServo, txtSvRpmUst, txtSvDereceUst, btnSvDondurUst, btnSvOrtalaUst, txtSvComUst,txtSvRpm,UST_SERVO_STR_ID);
}
private: System::Void btnSvOrtalaUst_Click(System::Object^  sender, System::EventArgs^  e) {
	btnSvOrtala_click_event(btnSvOrtalaUst,UST_SERVO_STR_ID);
}
private: System::Void btnSvDondurUst_Click(System::Object^  sender, System::EventArgs^  e) {
	btnSvDondur_click_event(btnSvDondurUst, txtSvRpmUst, txtSvDereceUst,UST_SERVO_STR_ID);
}


private: System::Void btnSrvSynConnect_Click(System::Object^  sender, System::EventArgs^  e) {
	btnServo_click_event(btnServo, txtSvRpmUst, txtSvDereceUst, btnSvDondurUst, btnSvOrtalaUst, txtSvComUst, txtSvRpm, SENKRON_SERVO_STR_ID);
}

private: System::Void btnSrvSynRotate_Click(System::Object^  sender, System::EventArgs^  e) {
	btnSvOrtala_click_event(btnSvOrtalaUst, SENKRON_SERVO_STR_ID);
}
private: System::Void btnSrvSynReset_Click(System::Object^  sender, System::EventArgs^  e) {
	btnSvDondur_click_event(btnSvDondurUst, txtSvRpmUst, txtSvDereceUst, SENKRON_SERVO_STR_ID);
}

};
}
