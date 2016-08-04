#include "Handle.h"

#include <iostream>
using namespace std;

Handle::Handle() {
	cout << "Handle::Handle()" << endl;
}

Handle::~Handle() {
	cout << "Handle::~Handle()" << endl;
}

Handle::Handle(Handle *succ) {
	this->_succ = succ;
	cout << "Handle::Handle(succ)" << endl;
}

void Handle::SetSuccessor(Handle *succ) {
	this->_succ = succ;
	cout << "Handle::SetSuccessor(succ)" << endl;
}

Handle *Handle::GetSuccessor() {
	cout << "Handle::GetSuccessor()" << endl;
	return this->_succ;
}

ConcreteHandleA::ConcreteHandleA() {
	cout << "ConcreteHandleA::ConcreteHandleA()" << endl;
}

ConcreteHandleA::~ConcreteHandleA() {
	cout << "ConcreteHandleA::~ConcreteHandleA()" << endl;
}

ConcreteHandleA::ConcreteHandleA(Handle *succ) : Handle(succ) {
	cout << "ConcreteHandleA::ConcreteHandleA(succ)" << endl;
}

void ConcreteHandleA::HandleRequest() {
	if (this->GetSuccessor() != 0) {
		cout << "ConcreteHandleA: Hand over to successor!" << endl;
		this->GetSuccessor()->HandleRequest();
	} else {
		cout << "ConcreteHandleA: No more successors, have to do myself." << endl;
	}
}

ConcreteHandleB::ConcreteHandleB() {
	cout << "ConcreteHandleB::ConcreteHandleB()" << endl;
}

ConcreteHandleB::~ConcreteHandleB() {
	cout << "ConcreteHandleB::~ConcreteHandleB()" << endl;
}

ConcreteHandleB::ConcreteHandleB(Handle *succ) : Handle(succ) {
	cout << "ConcreteHandleB::ConcreteHandleB(succ)" << endl;
}

void ConcreteHandleB::HandleRequest() {
	if (this->GetSuccessor() != 0) {
		cout << "ConcreteHandleB: Hand over to successor!" << endl;
		this->GetSuccessor()->HandleRequest();
	} else {
		cout << "ConcreteHandleB: No more successors, have to do myself." << endl;
	}
}
