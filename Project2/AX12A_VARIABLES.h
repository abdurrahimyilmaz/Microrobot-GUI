#ifndef AX12A_VARIABLES
#define AX12A_VARIABLES

#include <fstream>


constexpr int  AX_READ_DATA = 0X02;
constexpr int  AX_WRITE_DATA = 0X03;
constexpr int  AX_SPEED_ADRESS = 0X20;
constexpr int  AX_POSITION_PRESENT = 0X24;
constexpr int 	AX_POSITION_GOAL = 0X1E;
constexpr int  AX_START_COMMAND = 0XFF;
constexpr int  AX_SPEED_LENGTH = 0X02;
constexpr int  AX_POSITION_LENGTH = 0X02;
constexpr int  AX_BYTE = 0X01;

constexpr int  AX_SPEED_UPPER = 1023;
constexpr int  AX_SPEED_LOWER = 0;
constexpr int  AX_POSITION_UPPER = 1023;
constexpr int  AX_POSITION_LOWER = 0;
constexpr int  AX_POSITION_ERROR = 105;

constexpr int  POS_AX_MOTOR_ID_POS = 3;
constexpr int  POS_AX_DATA_LENGTH_POS = 4;
constexpr int  POS_AX_INSTRUCTION = 5;
constexpr int  POS_AX_PROPERTY_ID = 6;
constexpr int  POS_AX_NEW_PROPERTY_VAL = 7;
constexpr int  POS_AX_CHECKSUM_POS = 8;


constexpr int  AX_RPM_UPPER = 114;
constexpr int  AX_RPM_LOWER = 0;

constexpr int  AX_POS_MIDDLE = 512;
constexpr int  AX_POS_DEG_UPPER = 20;
constexpr int  AX_POS_DEG_LOWER = -20;
constexpr int  AX_ROTATING_ANGLE = 300;


#define ID_ALT_MOTOR 1
#define ID_UST_MOTOR 2


#endif