#include <iostream>
#include <functional>
#include <sstream>

using namespace std;

class Transaction {
	bool view;

public:
	virtual void enterPin() = 0;
	virtual void withdrawMoney() = 0;
	virtual void viewBalance() = 0;
	
	void setViewBalance(bool value_) {
		view = value_;
	}
	
	void pay() {
		enterPin();
		withdrawMoney();
		if (view)
			viewBalance();
	}
};

class OnlineTransaction : public Transaction {
public:
	void enterPin() { printf("OnlineTransaction: enter Pin\n"); }
	void withdrawMoney() { printf("OnlineTransaction: withdrawMoney\n"); }
	void viewBalance() { printf("OnlineTransaction: viewBalance\n"); }
};

class OfflineTransaction : public Transaction {
public:
	void enterPin() { printf("OfflineTransaction: enter Pin\n"); }
	void withdrawMoney() { printf("OfflineTransaction: withdrawMoney\n"); }
	void viewBalance() { printf("OfflineTransaction: viewBalance\n"); }
};


int main()
{
	Transaction *online = new OnlineTransaction;
	online->pay();
	
	Transaction *offline = new OfflineTransaction;
	offline->setViewBalance(true);
	offline->pay();

	return 0;
}
