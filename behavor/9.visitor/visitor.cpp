#include <iostream>
#include <functional>
#include <sstream>

using namespace std;

class CarPartVisitor;

class CarPart {
public:
	virtual ~CarPart() {}
	virtual void accept(CarPartVisitor *visitor) = 0;
};

class Engine;
class Wheel;
class Car;

class CarPartVisitor {
public:
	virtual ~CarPartVisitor() {}
	virtual void visit(Engine *engine) = 0;
	virtual void visit(Wheel *wheel) = 0;
	virtual void visit(Car *car) = 0;
};

class Engine : public CarPart {
public:
	Engine() {}

	void  accept(CarPartVisitor *visitor) {
		visitor->visit(&(*this));
	}
};

class Wheel: public CarPart {
	int num;

public:
	Wheel(int num_) : num(num_) {}

	void accept(CarPartVisitor *visitor) {
		visitor->visit(&(*this));
	}

	int getNum() { return num; }
};

class Car: public CarPart {
	CarPart *parts[5];

public:
	Car() {
		parts[0] = new Engine();
		parts[1] = new Wheel(1);
		parts[2] = new Wheel(2);
		parts[3] = new Wheel(3);
		parts[4] = new Wheel(4);
	}

	void accept(CarPartVisitor *visitor) {
		visitor->visit(&(*this));

		for (int i = 0; i < 5; i++)
			parts[i]->accept(visitor);
	}
};

class RountineCarPartVisitor : public CarPartVisitor {
public:
	void visit(Car *car) {
		printf("visit car\n");
	}

	void visit(Engine *engine) {
		printf("visit Engine\n");
	}

	void visit(Wheel *wheel) {
		printf("visit wheel:%d\n", wheel->getNum());
	}
};

int main()
{
	Car car;
	RountineCarPartVisitor rcpv;

	car.accept(&rcpv);

	return 0;
}

