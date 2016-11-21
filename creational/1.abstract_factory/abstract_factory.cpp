#include <iostream>
#include <list>
#include <memory>

using namespace std;

class Shell;
class SSHShell;
class TellNetShell;

class ExecCommand;
class SSHCommand;
class TelNetCommand;

class Shell {
public:
	virtual ~Shell() {}
	virtual void connect() = 0;
};

class SSHShell : public Shell {
public:
	void connect() override final { printf("SSH: connec\n"); }
};

class TellNetShell : public Shell {
public:
	void connect() override final { printf("TellNet: connect\n"); }
};

class ExecCommand {
public:
	virtual ~ExecCommand() {}
	virtual void execute() = 0;
};

class SSHCommand : public ExecCommand {
public:
	virtual void execute() { printf("TellNet: execute\n"); }
};

class TelNetCommand : public ExecCommand {
public:
	virtual void execute() { printf("TellNet: execute\n"); }
};


class AbstractFactory {
public:
	virtual ~AbstractFactory() {}
	virtual shared_ptr<Shell> ctreateShell() = 0;
	virtual shared_ptr<ExecCommand> ctreateCommand() = 0;
};

class SSHFactory : public AbstractFactory {
public:
	shared_ptr<Shell> ctreateShell() override final { return shared_ptr<Shell> (new SSHShell); }
	shared_ptr<ExecCommand> ctreateCommand() override final { return shared_ptr<ExecCommand> (new SSHCommand); }
};

class TelNetFactory : public AbstractFactory {
public:
	shared_ptr<Shell> ctreateShell() override final { return shared_ptr<Shell> (new TellNetShell); }
	shared_ptr<ExecCommand> ctreateCommand() override final { return shared_ptr<ExecCommand> (new TelNetCommand); }
};


int main()
{
	TelNetFactory tel_net_factroy;

	shared_ptr<Shell> shell = tel_net_factroy.ctreateShell();
	shell->connect();

	shared_ptr<ExecCommand> cmd = tel_net_factroy.ctreateCommand();
	cmd->execute();

    return 0;
}
