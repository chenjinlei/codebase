#include "Context.h"
#include "State.h"

#include <iostream>
using namespace std;

Context::Context() {
	cout << "Context::Context() (default) called..." << endl;
}

Context::Context(State *state) {
	this->_state = state;
	cout << "Context::Context() called..." << endl;
}

Context::~Context() {
	delete this->_state;
	cout << "Context::~Context() called..." << endl;
}

void Context::OperationInterface() {
	this->_state->OperationInterface(this);
	cout << "Context::OperationInterface() called..." << endl;
}

void Context::OperationChangeState() {
	this->_state->OperationChangeState(this);
	cout << "Context::OperationChangeState() called..." << endl;
}

bool Context::ChangeState(State *state) {
	this->_state = state;
	return true;
}
