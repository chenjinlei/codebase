#include "Receiver.h"
#include "Command.h"
#include "Invoker.h"

#include <iostream>
using namespace std;

Invoker::Invoker(Command *cmd) {
	this->_cmd = cmd;
	cout << "Invoker::Invoker()" << endl;
}

Invoker::~Invoker() {
	delete this->_cmd;
	cout << "Invoker::~Invoker()" << endl;
}

void Invoker::Invoke() {
	this->_cmd->Execute();
}
