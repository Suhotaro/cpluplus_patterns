#include <iostream>
#include <list>
#include <memory>

using namespace std;

/* Adaptee */
class Programmer {
public:
	void writeProgram() { printf("write Program\n"); }
	void writeScript() { printf("write Script\n"); }
	void writeConfigFile() { printf("write Config file\n"); }
};

/* Target */
class Chief
{
public:
	virtual ~Chief() {}

	virtual void bakeCake() = 0;
	virtual void cookSoup() = 0;
	virtual void fryEggs() = 0;
};

/* Adapter */
class ChiefAdapter : public Chief, private Programmer
{

public:
	void bakeCake() { writeProgram(); }
	void cookSoup() { writeScript(); }
	void fryEggs() { writeConfigFile(); }
};

/* Client */
int main()
{
	ChiefAdapter chief_adapter;

	chief_adapter.cookSoup();
	chief_adapter.bakeCake();
	chief_adapter.fryEggs();

    return 0;
}
