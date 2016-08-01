#include "Receiver.h"
#include "Command.h"

#include <iostream>
using namespace std;

Command::Command() {
	cout << "Command::Command()" << endl;
}

Command::~Command() {
	cout << "Command::~Command()" << endl;
}

void Command::Execute() {
	cout << "Command::Execute()" << endl;
}

ConcreteCommand::ConcreteCommand(Receiver *recv) {
	this->_recv = recv;
}

ConcreteCommand::~ConcreteCommand() {
	delete this->_recv;
	cout << "ConcreteCommand::~ConcreteCommand()" << endl;
}

void ConcreteCommand::Execute() {
	this->_recv->Action();
	cout << "ConcreteCommand::Execute()" << endl;
}
