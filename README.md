# device-monitoring
This is the README file for the following project

CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Requirements
 * Implementation
 * Setup and Run
 
_Introduction_
This repository contains the solution for the following problem.

        You monitor devices, which are sending data to you.
        Each device has a unique name.
        Each device produces measurements.
The challenge is:
        Compute number of messages you got or read from the devices.

_Requirements_
  The solution shall be written in C++ language (preferably C++17 or newer).
  The scope is open, you must decide how the “devices” will work in your system.
  The solution should be posted on GitHub or a similar page for a review.
  Please add documentation explaining us how to compile and run your code.

_Implementation_
  There are 5 differenc code files in the repository to solve the given task.
    main.cpp - contains the main function implementation.
    device.h - contains the declaration of the classes Device, SimpleDevice and SmartDevice
    device.cpp - contains the implementation of the classes Device, SimpleDevice and SmartDevice
    monitor.h - contains the declaration of the class Monitor
    monitor.cpp - contains the definition of the class Monitor

  Monitor class object acts like platform which can support different devices. Currently 2 types of devices are available - SmartDevice and SimpleDevice.
  The main function instantiates the Device objects and registeres them on the Monitor 'platform'. 
  It runs the devices, which are responsible to create and send messages to Monitor. Monitor class prints all the messages to screen. 
  The app will run infinite and you can see messages from different devices. Please press CTRL+C to stop the current run. 

 
_Setup and Run_
 This branch contains 5 project files(cpp/h) with the code and a simple executable to run the code in Windows.  
 You can run it if you wish by just double-clicking on it.

 



