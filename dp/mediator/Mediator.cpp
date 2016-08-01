#include "Mediator.h"
#include "Colleage.h"

#include <string>
#include <iostream>
using namespace std;

Mediator::Mediator() {
	cout << "Mediator::Mediator()" << endl;
}

Mediator::~Mediator() {
	cout << "Mediator::~Mediator()" << endl;
}

ConcreteMediator::ConcreteMediator() {
	cout << "ConcreteMediator::ConcreteMediator()" << endl;
}

ConcreteMediator::ConcreteMediator(Colleage *clgA, Colleage *clgB) {
	this->_clgA = clgA;
	this->_clgB = clgB;
}

ConcreteMediator::~ConcreteMediator() {
	cout << "ConcreteMediator::~ConcreteMediator()" << endl;
}

void ConcreteMediator::SetConcreteColleageA(Colleage *clgA) {
	this->_clgA = clgA;
}

void ConcreteMediator::SetConcreteColleageB(Colleage *clgB) {
	this->_clgB = clgB;
}

Colleage *ConcreteMediator::GetConcreteColleageA() {
	return this->_clgA;
}

Colleage *ConcreteMediator::GetConcreteColleageB() {
	return this->_clgB;
}

void ConcreteMediator::IntroColleage(Colleage *clgA, Colleage *clgB) {
	this->_clgA = clgA;
	this->_clgB = clgB;
}

void ConcreteMediator::DoActionFromAtoB() {
	(*this->_clgB).SetState(this->_clgA->GetState());
}

void ConcreteMediator::DoActionFromBtoA() {
	(*this->_clgA).SetState(this->_clgB->GetState());
}
