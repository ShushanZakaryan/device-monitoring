#pragma once
#include "monitor.h"
#include <string>

//Abstruct base class for Device object. 
//It operates on the platform, creates and send messages to Platform(currently monitor object)
class Device
{
public:
	//Construction and destruction of the object
	Device();
	Device(string, int, Monitor*);
	Device(const Device&);
	Device& operator=(const Device&);
	virtual ~Device();

	//Sets and gets the Device specific information
	void setName(const string&);
	string getName() const;
	void setId(int);
	int getId() const;
	void setMonitor(const Monitor&);
	Monitor* getMonitor();
	Monitor* getMonitor() const;

	//Run the device, this function should be defined in all derived classes
	virtual void run() = 0;
	//Creates and sends messages, this function should be defined in all derived classes
	virtual void sendMessage(const string&, Monitor*) = 0;

private:
	string _name;
	int _id;
	Monitor* _m;
};


//Derived class which represents the simple device.
//It is generating random numbers and sends them to Monitor object
class SimpleDevice : public Device
{
public:
	//Construction and destruction of the object
	SimpleDevice();
	SimpleDevice(string, int, Monitor* );
	virtual ~SimpleDevice();

	//Runs the Simple device, it generates random numbers
	virtual void run();
	//Sends Simple message to Monitor object
	virtual void sendMessage(const string&, Monitor*);
};

//Derived class which represents the smart device.
//it generates current date and time and sends them to Monitor object
class SmartDevice : public Device
{
public:
	//Construction and destruction of the object
	SmartDevice();
	SmartDevice(string, int, Monitor*);
	virtual ~SmartDevice();

	//Runs the Smart device, it generates current date and time as a message
	virtual void run();
	//Sends Smart message to Monitor object
	virtual void sendMessage(const string&, Monitor*);
};

