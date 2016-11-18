#include <iostream>
#include <string>

using namespace std;

class Colleague;
class Mediator;
class FirstColleague;
class SecondColleague;


class Mediator {
public:
	virtual void send(string const& message, Colleague *colleague) const = 0;
};

class Colleague {
protected:
	Mediator *mediator;

public:
	explicit Colleague(Mediator *mediator_) : mediator(mediator_) {}
};

class FirstColleague : public Colleague {
public:
	explicit FirstColleague(Mediator *mediator_) : Colleague(mediator_) {}

	void send(string const& message) { mediator->send(message, this); }
	void notify(string const& message) { printf("First Colleague gets message: %s\n", message.c_str()); }
};

class SecondColleague : public Colleague {
public:
	explicit SecondColleague(Mediator *mediator_) : Colleague(mediator_) {}

	void send(string const& message) { mediator->send(message, this); }
	void notify(string const& message) { printf("Second Colleague gets message: %s\n", message.c_str()); }
};

class ConcreteMediator : public Mediator {
protected:
	FirstColleague *colleague1;
	SecondColleague *colleague2;

public:
	void set_colleague(FirstColleague *colleague) { colleague1 = colleague; }
	void set_colleague(SecondColleague *colleague) { colleague2 = colleague; }

	//void set_colleague(SecondColleague *colleague) { colleague1 = colleague; }

	void send(string const& message, Colleague *colleague) const override final {
		if (colleague == colleague1) {
			colleague2->notify(message);
		}
		else if (colleague == colleague2) {
			colleague1->notify(message);
		}
	}
};

int main()
{
	ConcreteMediator m;

	FirstColleague c1(&m);
	SecondColleague c2(&m);

	m.set_colleague(&c1);
	m.set_colleague(&c2);

	c1.send("How are you?");
	c2.send("Fine, thanks");
	c2.send("And how are you?");
	c1.send("Fantastic, thanks");

	return 0;
}

