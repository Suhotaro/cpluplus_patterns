#include <iostream>
#include <list>

using namespace std;


class SupportEngineer
{
public:
	typedef enum
	{
		TYPE_BASIC = 1,
		TYPE_APPLICATION,
		TYPE_FINANCIAL,
	} engineer_type;

	SupportEngineer(engineer_type type_) : type(type_) {}
	virtual ~SupportEngineer() {}

	SupportEngineer * setNext(SupportEngineer *next_)
	{
		next = next_; return next;
	}

	void message (string msg_, engineer_type type_)
	{
		if (type == type_)
			process(msg_);
		else if (next != NULL)
			next->message(msg_, type_);
	}

	virtual void process(string msg_) = 0;

protected:
	engineer_type type;
	SupportEngineer *next;
};

class BasicSupportEngineer : public SupportEngineer
{
public:
	BasicSupportEngineer() : SupportEngineer(TYPE_BASIC) {}
	~BasicSupportEngineer() { if (next) delete next; }

	virtual void process(string msg_)
	{
		printf("BasicSupportEngineer: %s\n",msg_.c_str());
	}
};

class ApplicationSupportEngineer : public SupportEngineer
{
public:
	ApplicationSupportEngineer() : SupportEngineer(TYPE_APPLICATION) {}
	~ApplicationSupportEngineer() { if (next) delete next; }

	virtual void process(string msg_)
	{
		printf("ApplicationSupportEngineer: %s\n",msg_.c_str());
	}
};

class FinancialSupportEngineer : public SupportEngineer
{
public:
	FinancialSupportEngineer() : SupportEngineer(TYPE_FINANCIAL) {}
	~FinancialSupportEngineer() { if (next) delete next; }

	virtual void process(string msg_)
	{
		printf("FinancialSupportEngineer: %s\n",msg_.c_str());
	}
};

int main()
{
	SupportEngineer *bse = new BasicSupportEngineer();
	bse->setNext(new ApplicationSupportEngineer())->setNext(new FinancialSupportEngineer());

	bse->message("job for basic", SupportEngineer::TYPE_BASIC);
	bse->message("job for application", SupportEngineer::TYPE_APPLICATION);
	bse->message("job for financail", SupportEngineer::TYPE_FINANCIAL);

	delete bse;

    return 0;
}

