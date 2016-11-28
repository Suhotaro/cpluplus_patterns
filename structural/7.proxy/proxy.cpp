#include <map>
#include <iostream>
#include <string>

using namespace std;

class IMath {
public:
	virtual double add(double, double) = 0;
	virtual double sub(double, double) = 0;
	virtual double mul(double, double) = 0;
	virtual double div(double, double) = 0;
};

class Math : public IMath {
public:
	virtual double add(double x, double y) { return x+y; }
	virtual double sub(double x, double y) { return x-y; }
	virtual double mul(double x, double y) { return x*y; }
	virtual double div(double x, double y) { return x/y; }
};

class MathProxy : public IMath {
	IMath *math;
public:
	MathProxy() { math = new Math; }

	virtual double add(double x, double y) { return math->add(x, y); }
	virtual double sub(double x, double y) { return math->sub(x, y); }
	virtual double mul(double x, double y) { return math->mul(x, y); }
	virtual double div(double x, double y) { return math->div(x, y); }
};

/* Client */
int main() {

	MathProxy math_proxy;

	cout << "4 + 2 = " << math_proxy.add(4, 2) << endl;
	cout << "4 - 2 = " << math_proxy.sub(4, 2) << endl;
	cout << "4 * 2 = " << math_proxy.mul(4, 2) << endl;
	cout << "4 / 2 = " << math_proxy.div(4, 2) << endl;

    return 0;
};

