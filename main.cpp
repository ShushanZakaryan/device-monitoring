#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "monitor.h"
#include "device.h"

using namespace std;

//Function that will run the devices and process the messages
void run(Monitor* m)
{
	if (m->getDeviceCount())
	{
		set<Device*> devs = m->getDevices();
		if (!devs.size())
		{
			cout << "No devices to run. Exiting!\n";
			return;
		}
		while (true) {
			for (set<Device*>::iterator it = devs.begin(); it != devs.end(); ++it)
			{
				Device* dev = *it;
				if (dev == nullptr)
					continue;
				dev->run();
				m->readAllMessages();
			}
		}
	}
}

void interupt_handler(int signum) {
	printf("Exiting the application. %d\n", signum);
	exit(signum);
}

int main()
{
	//setting up the Monitor object to watch all the devices.
	Monitor* m = new Monitor("Monitor"); 
	//setting up devices to run and send messages to Monitor object
	Device* d1 = new SmartDevice("d1", 1, m); 
	Device* d2 = new SmartDevice("d2", 2, m);
	Device* d3 = new SmartDevice("d3", 3, m);
	Device* d4 = new SimpleDevice("d4", 4, m);
	
	//registering the devices on the 'platform'
	m->addDevice(d1);
	m->addDevice(d2);
	m->addDevice(d3);
	m->addDevice(d4);

	signal(SIGINT, interupt_handler);

	run(m);
	
	delete m, d1, d2, d3, d4;
	return 0;
}