#include <iostream>
#include <list>
#include <memory>

using namespace std;

class AbstractProductA {
public:
	virtual ~AbstractProductA() {}
};

class AbstractProductB {
public:
	virtual ~AbstractProductB() {}
	virtual void interract(AbstractProductA *apA) = 0;
};

class ProductA1 : public AbstractProductA {};
class ProductB1 : public AbstractProductB {
public:
	void interract(AbstractProductA *apA) {
		printf("B1:%p interract with A:%p\n", &(*this), apA);
	}
};

class ProductA2 : public AbstractProductA {};
class ProductB2 : public AbstractProductB {
public:
	void interract(AbstractProductA *apA) {
		printf("B2:%p interract with A:%p\n", &(*this), apA);
	}
};

class AbstractFactory {
public:
	virtual ~AbstractFactory() {}
	virtual AbstractProductA* createProductA() = 0;
	virtual AbstractProductB* createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
	AbstractProductA* createProductA() { return new ProductA1; }
	AbstractProductB* createProductB() { return new ProductB1; }
};

class ConcreteFactory2 : public AbstractFactory {
public:
	AbstractProductA* createProductA() { return new ProductA2; }
	AbstractProductB* createProductB() { return new ProductB2; }
};

class Client {
	AbstractProductA *productA;
	AbstractProductB *productB;

public:
	Client(AbstractFactory *abstract_factroy) {
		productA = abstract_factroy->createProductA();
		productB = abstract_factroy->createProductB();
	}

	~Client() {
		if (productA)
			delete productA;
		if (productB)
			delete productB;
	}

	void execute() { productB->interract(productA); }
};

int main()
{
	ConcreteFactory1 concreate_factory_1;
	Client client_1(&concreate_factory_1);
	client_1.execute();

	ConcreteFactory2 concreate_factory_2;
	Client client_2(&concreate_factory_2);
	client_2.execute();

    return 0;
}

