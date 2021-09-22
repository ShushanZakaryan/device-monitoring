#include "monitor.h"
#include <iostream>

using namespace std;

Monitor::Monitor()
{
	_name = "";
	_msgBuffer.clear();
	_registeredDevices.clear();
}

Monitor::Monitor(string n)
{
	_name = n;
	_msgBuffer.clear();
	_registeredDevices.clear();
}

Monitor::~Monitor()
{
	_name = "";
	_msgBuffer.clear();

	auto it = _registeredDevices.begin(); 

	for (; it != _registeredDevices.end(); ++it)
		delete *it;  //TODO.SHUSHAN warning

	_registeredDevices.clear(); 
}

string Monitor::getName() const
{
	return _name;
}

void Monitor::setName(const string& n) 
{
	_name = n;
}

void Monitor::addMessage(const string& msg, int id)
{
	_msgBuffer.insert(make_pair(id, msg));
}

set<Device*> Monitor::getDevices() const
{
	return _registeredDevices;
}

size_t Monitor::getDeviceCount() const
{
	return _registeredDevices.size();
}

void Monitor::addDevice(Device* dev) 
{
	if(dev != nullptr)
		_registeredDevices.insert(dev);
}

void Monitor::removeDevice(Device* dev)
{
	if (dev != nullptr)
		_registeredDevices.erase(dev);
}

void Monitor::readMsgFromDevice(int id)
{
	if (!_msgBuffer.size())
		cout << "No Messages to print !!!" << endl;

	typedef multimap<int, string>::const_iterator it_map;
	auto msgList = _msgBuffer.equal_range(id);
	
	for (it_map it = msgList.first; it != msgList.second; it++)
	{
		cout << "Message from Device #" << it->first << " : " << it->second << endl;
		_msgBuffer.erase(it);
	}
}

void Monitor::readAllMessages()
{
	auto it_begin = _msgBuffer.begin();

	for (; it_begin != _msgBuffer.end(); ++it_begin)
		cout << "Message from Device #" << (*it_begin).first << " : " << (*it_begin).second << endl;
	clearMsgBuffer();
}

void Monitor::clearMsgBuffer()
{
	_msgBuffer.clear();
}