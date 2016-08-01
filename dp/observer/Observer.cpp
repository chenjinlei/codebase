#include "Subject.h"
#include "Observer.h"

#include <iostream>
#include <string>
using namespace std;

Observer::Observer() {
	this->_st = '\0';
	cout << "Observer::Observer() called..." << endl;
}

Observer::~Observer() {
	cout << "Observer::~Observer() called..." << endl;
}

ConcreteObserverA::ConcreteObserverA(Subject *sub) {
	this->_sub = sub;
	this->_sub->Attach(this);
	cout << "ConcreteObserverA object constructed..." << endl;
}

ConcreteObserverA::~ConcreteObserverA() {
	this->_sub->Detach(this);

	if (this->_sub != 0) {
		delete this->_sub;
	}
}

Subject *ConcreteObserverA::GetState() {
	return this->_sub;
}

void ConcreteObserverA::Update(Subject *sub) {
	this->_sub = sub;
	PrintInfo();
}

void ConcreteObserverA::PrintInfo() {
	cout << "ConcreteObserverA observer" << this->_sub->GetState() << endl;
}

ConcreteObserverB::ConcreteObserverB(Subject *sub) {
	this->_sub = sub;
	this->_sub->Attach(this);
}

ConcreteObserverB::~ConcreteObserverB() {
	this->_sub->Detach(this);

	if (this->_sub != 0) {
		delete this->_sub;
	}
}

Subject *ConcreteObserverB::GetSubject() {
	return this->_sub;
}

void ConcreteObserverB::Update(Subject *sub) {
	this->_sub = sub;
	PrintInfo();
}

void ConcreteObserverB::PrintInfo() {
	cout << "ConcreteObserverB Obseerver" << this->_sub->GetState() << endl;
}
