#ifndef SERIALPORT_H_
#define SERIALPORT_H_

#include <windows.h>

class SerialPort {
private:
	HANDLE serialPortHandle;

public:
	SerialPort();
	~SerialPort();

	int connect();
	int connect(const wchar_t *device);
	//int connect (char *deviceName, int baudRate, SerialParity parity);
	void disconnect(void);

	int sendArray(unsigned char *buffer, int len);
	int getArray(unsigned char *buffer, int len);

	void clear();
};


#endif /* SERIALPORT_H_ */