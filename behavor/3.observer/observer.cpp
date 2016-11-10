#include <iostream>
#include <list>

using namespace std;

class Subject;

class Observer {
public:
	Observer() {}
	virtual ~Observer() {}

	virtual void update(string msg) = 0;
	virtual void setSubject(Subject *subject) = 0;
};

class Subject {
public:
	Subject() {}
	virtual ~Subject() {}

	virtual void registerObs(Observer *obs) = 0;
	virtual void unregisterObs(Observer *obs) = 0;
	virtual void notifyObservers() = 0;
};

class OfficeChat : public Subject {
	list<Observer*> observers;
	list<string> messages;
	bool changed = false;

public:
	OfficeChat() {}
	virtual ~OfficeChat() {}

	void addMessage(string msg) {
		messages.push_back(msg);
		changed = true;
	}

	void registerObs(Observer *obs) {
		observers.push_back(obs);
	}

	void unregisterObs(Observer *obs) {
		observers.remove(obs);
	}

	void notifyObservers() {
		if (changed) {
			for (Observer* obs : observers)
				for (string msg : messages)
					obs->update(msg);
			changed = false;
		}
	}
};

class Worker : public Observer
{
	Subject *subject;

public:
	void update(string msg) { printf("do processing: %s\n", msg.c_str()); }
	void setSubject (Subject *subject) { subject = subject; }
};

int main()
{
	OfficeChat *oc = new OfficeChat;
	for( int i = 0; i < 2; i++ )
	{
		Observer *obs = new Worker;
		oc->registerObs(obs);
		obs->setSubject(oc);
	}

	oc->addMessage("new message");
	oc->notifyObservers();

    return 0;
}
