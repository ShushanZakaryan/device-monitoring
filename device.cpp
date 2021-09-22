#include "device.h"
#include<iostream>
#include <ctime>
#include <chrono>
#include <thread>

Device::Device()
{
	_name = "";
	_id = -1;
	_m = new Monitor();
}

Device::Device(string name, int id, Monitor* m)
{
	_name = name;
	_id = id;
	_m = m;
}

Device::Device(const Device& other)
{
	_name = other.getName();
	_id = other.getId();
	_m = new Monitor(*other.getMonitor());
}

Device& Device::operator=(const Device& other)
{
	if (this == &other)
		return *this;
	
	_name = other.getName();
	_id = other.getId();
	_m = new Monitor(*other.getMonitor()); 

	return *this;
}

Device::~Device()
{
	_m = nullptr;
}

void Device::setName(const string& n)
{
	_name = n;
}

string Device::getName() const
{
	return _name;
}

void Device::setId(int id)
{
	_id = id;
}

int Device::getId()  const
{
	return _id;
}

void Device::setMonitor(const Monitor& m) 
{
	_m = new Monitor(m);
}

Monitor* Device::getMonitor() 
{
	return _m;
}

Monitor* Device::getMonitor() const
{
	return _m;
}

////////////////////////////SimpleDevice class functionality//////////////////////////
SimpleDevice::SimpleDevice() 
{
}

SimpleDevice::SimpleDevice(string name, int id, Monitor* m) 
	:Device(name, id, m)
{}

SimpleDevice::~SimpleDevice()
{}

void SimpleDevice::run()
{
	int num = rand() % 10;
	string msg = "Message: " + to_string(num);
	sendMessage(msg, getMonitor());
}

void SimpleDevice::sendMessage(const string& msg, Monitor* m)
{
	if (msg.empty() || m == nullptr)
		return;
	m->addMessage(msg, getId());
}

////////////////////////////SmartDevice class functionality//////////////////////////

SmartDevice::SmartDevice()
{}

SmartDevice::SmartDevice(string name, int id, Monitor* m)
	:Device(name, id, m)
{}

SmartDevice::~SmartDevice()
{}

void SmartDevice::run()
{
	const auto start = std::chrono::system_clock::now();
	std::this_thread::sleep_for(2000ms);
	const auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	const std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	char str[26];
	ctime_s(str, sizeof(str), &end_time);

	string msg = "Message: ";
	msg += str;
	sendMessage(msg, getMonitor());
}

void SmartDevice::sendMessage(const string& msg,Monitor* m)
{
	if (m == nullptr || msg.empty())
		return;

	m->addMessage(msg, getId());
}

