#pragma once
#include <string>
#include <map>
#include <set>

using namespace std;

class Device;

//Class which is operating as a platform. It registeres different devices and processes requests from them.
class Monitor
{
public:
	//construction and destruction of the object
	Monitor();;
	Monitor(string);
	~Monitor();

	//gets and sets the name of the Monitorer
	string getName() const;
	void setName(const string& name);

	//Return all the registered devices
	set<Device*> getDevices() const;
	
	//Adding and removing devices to Monitor obj
	void addDevice(Device*);
	void removeDevice(Device*);
	//Returns current available devices
	size_t getDeviceCount() const;
	//Adding messages for the Monitor to process. Eg print
	void addMessage(const string&, int);
	//Clear all the messages from buffer
	void clearMsgBuffer();

	//Processes the message from particular device
	virtual void readMsgFromDevice(int);
	//Process te messages, Will print them on the screen
	virtual void readAllMessages();
	
private:
	string _name;  //Name of the Monitor obj.
	multimap<int, string> _msgBuffer;  //Buffer to keep messages
	set<Device*> _registeredDevices;	//List of available devices
};
