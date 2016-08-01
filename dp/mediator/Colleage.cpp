#include "Mediator.h"
#include "Colleage.h"

#include <string>
#include <iostream>
using namespace std;

Colleage::Colleage() {
	cout << "Colleage::Colleage()" << endl;
}

Colleage::Colleage(Mediator *mdt) {
	this->_mdt = mdt;
	cout << "Colleage::Colleage(mdt)" << endl;
}

Colleage::~Colleage() {
	cout << "Colleage::~Colleage()" << endl;
}

ConcreteColleageA::ConcreteColleageA() {
	cout << "ConcreteColleageA::ConcreteColleageA()" << endl;
}

ConcreteColleageA::ConcreteColleageA(Mediator *mdt) : Colleage(mdt) {
	cout << "ConcreteColleageA::ConcreteColleageA(mdt)" << endl;
}

ConcreteColleageA::~ConcreteColleageA() {
	cout << "ConcreteColleageA::~ConcreteColleageA()" << endl;
}

void ConcreteColleageA::Action() {
	_mdt->DoActionFromAtoB();
	cout << "State of ConcreteColleageB: " << this->GetState() <<endl;
}

void ConcreteColleageA::SetState(const string &st) {
	this->_st = st;
}

string ConcreteColleageA::GetState() {
	return this->_st;
}

ConcreteColleageB::ConcreteColleageB() {
	cout << "ConcreteColleageB::ConcreteColleageB()" << endl;
}

ConcreteColleageB::ConcreteColleageB(Mediator *mdt) : Colleage(mdt) {
	this->_mdt = mdt;
	cout << "ConcreteColleageB::ConcreteColleageB(mdt)" << endl;
}

ConcreteColleageB::~ConcreteColleageB() {
	cout << "ConcreteColleageB::~ConcreteColleageB()" << endl;
}

void ConcreteColleageB::Action() {
	this->_mdt->DoActionFromBtoA();
	cout << "State of ConcreteColleageA: " << this->GetState() << endl;
}

void ConcreteColleageB::SetState(const string &st) {
	this->_st = st;
}

string ConcreteColleageB::GetState() {
	return this->_st;
}
