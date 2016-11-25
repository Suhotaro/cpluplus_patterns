#include <memory>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class IComponent {
public:
	virtual void operation() = 0;
	virtual ~IComponent() {}
};

class Component : public IComponent {
public:
	virtual void operation() {
		cout << "World!" << endl;
	}
};

class DecoratorOne : public IComponent {
	shared_ptr<IComponent> m_component;
public:
	DecoratorOne(IComponent *component) : m_component(component) {}

	virtual void operation() {
		cout << ", ";
		m_component->operation();
	}
};

class DecoratorTwo : public IComponent {
	shared_ptr<IComponent> m_component;
public:
	DecoratorTwo(IComponent *component) : m_component(component) {}

	virtual void operation() {
		cout << "Hello";
		m_component->operation();
	}
};

int main()
{
	DecoratorTwo obj(new DecoratorOne(new Component()));
	obj.operation();

    return 0;
}

