

#include "SerialPort.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Windows::Forms;

SerialPort::SerialPort() {
	serialPortHandle = INVALID_HANDLE_VALUE;
}

SerialPort::~SerialPort() {
	if (serialPortHandle != INVALID_HANDLE_VALUE)
		CloseHandle(serialPortHandle);

	serialPortHandle = INVALID_HANDLE_VALUE;
}

int SerialPort::connect() {
	return connect(L"COM3");
}

int SerialPort::connect(const wchar_t* device) {
	int error = 0;
	DCB  dcb;

	memset(&dcb, 0, sizeof(dcb));

	dcb.DCBlength = sizeof(dcb);

	dcb.BaudRate = 1000000;
	dcb.Parity = NOPARITY;
	dcb.fParity = 0;
	dcb.StopBits = ONESTOPBIT;
	dcb.ByteSize = 8;
	
	serialPortHandle = CreateFile(device, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, 0);

	if (serialPortHandle != INVALID_HANDLE_VALUE) {
		if (!SetCommState(serialPortHandle, &dcb))
			error = 2;
	}
	else {
		error = 1;
		MessageBox::Show("AN ERROR OCCURED WHILE CONNECTING TO PORT");
		return error;
	}

	if (error != 0) {
		disconnect();
	}
	else {
		clear();
	}

	return error;
}

void SerialPort::disconnect(void) {
	CloseHandle(serialPortHandle);
	serialPortHandle = INVALID_HANDLE_VALUE;

	//printf("Port 1 has been CLOSED and %d is the file description\n", fileDescriptor);
}

int SerialPort::sendArray(unsigned char *buffer, int len) {
	unsigned long result;

	if (serialPortHandle != INVALID_HANDLE_VALUE)
		WriteFile(serialPortHandle, buffer, len, &result, NULL);

	return result;
}

int SerialPort::getArray(unsigned char *buffer, int len) {
	unsigned long read_nbr;

	read_nbr = 0;
	if (serialPortHandle != INVALID_HANDLE_VALUE)
	{
		ReadFile(serialPortHandle, buffer, len, &read_nbr, NULL);
	}

	return((int)read_nbr);
}

void SerialPort::clear() {
	PurgeComm(serialPortHandle, PURGE_RXCLEAR | PURGE_TXCLEAR);
}
