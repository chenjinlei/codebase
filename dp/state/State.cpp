#include "Context.h"
#include "State.h"

#include <iostream>
using namespace std;

State::State() {
	cout << "State::State() called..." << endl;
}

State::~State() {
	cout << "State::~State() called..." << endl;
}

void State::OperationInterface(Context *con) {
	cout << "State::OperationInterface(con)" << endl;
}

void State::OperationChangeState(Context *con) {
	cout << "State::OperationChangeState(con)" << endl;
}

bool State::ChangeState(Context *con, State *st) {
	con->ChangeState(st);
	return true;
}

ConcreteStateA::ConcreteStateA() {
	cout << "ConcreteStateA::ConcreteStateA() called..." << endl;
}

ConcreteStateA::~ConcreteStateA() {
	cout << "ConcreteStateA::~ConcreteStateA() called..." << endl;
}

void ConcreteStateA::OperationInterface(Context *con) {
	cout << "ConcreteStateA::OperationInterface(con) called..." << endl;
}

void ConcreteStateA::OperationChangeState(Context *con) {
	cout << "ConcreteStateA::OperationChangeState(con)" << endl;
}

ConcreteStateB::ConcreteStateB() {
	cout << "ConcreteStateB::ConcreteStateB() called..." << endl;
}

ConcreteStateB::~ConcreteStateB() {
	cout << "ConcreteStateB::~ConcreteStateB() called..." << endl;
}

void ConcreteStateB::OperationInterface(Context *con) {
	cout << "ConcreteStateB::OperationInterface(con)" << endl;
}

void ConcreteStateB::OperationChangeState(Context *con) {
	cout << "ConcreteStateB::ChangeState(con)" << endl;
}
