#include <iostream>
#include <list>

using namespace std;

class Command {
public:
	Command() {}
	virtual ~Command() {}

	virtual void execute() = 0;
};

class Device {
public:
	Device() {}
	~Device() {}

	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
};


class TurnOnCommand : public Command {
	Device *device;

public:
	TurnOnCommand(Device *device_) : device(device_) {}
	void execute() override { device->turnOn(); }
};

class TurnOffCommand : public Command {
	list<Device *> devices;

public:
	TurnOffCommand(list<Device *>devices_) : devices(devices_) {}
	void execute() override {
		for ( Device *dev : devices )
			dev->turnOff();
	}
};

class TV : public Device
{
public:
	void turnOn() override { printf("TV turned ON\n"); }
	void turnOff() override { printf("TV turned OFF\n"); }
};

class Lamp : public Device
{
	string location;

public:
	Lamp(string location_) : location(location_) {}

	void turnOn() override { printf("LAMP in %s turned ON\n", location.c_str()); }
	void turnOff() override { printf("LAMP in %s turned OFF\n", location.c_str()); }
};

class Switch {
	list<string> log;

public:
	void logAndExecute(Command * command) {
		command->execute();
	}
};

int main()
{
	TV *tv = new TV;
	Lamp *kitchenLamp = new Lamp("kitchen");
	Lamp *bedroomLamp = new Lamp("bedroom");

	list<Device *> lamps;
	lamps.push_back(kitchenLamp);
	lamps.push_back(bedroomLamp);

	Command *cm1 = new TurnOnCommand(tv);
	Command *cm2 = new TurnOffCommand(lamps);

	Switch *sw = new Switch;
	sw->logAndExecute(cm1);
	sw->logAndExecute(cm2);

    return 0;
}
