#include "Facade.h"

#include <iostream>
using namespace std;

Subsystem1::Subsystem1() {
	cout << "Subsystem1 object constructed..." << endl;
}

Subsystem1::~Subsystem1() {
	cout << "Subsystem1 object destructed..." << endl;
}

void Subsystem1::Operation() {
	cout << "Subsystem1::Operation()" << endl;
}

Subsystem2::Subsystem2() {
	cout << "Subsystem2 object constructed..." << endl;
}

Subsystem2::~Subsystem2() {
	cout << "Subsystem2 destructed..." << endl;
}

void Subsystem2::Operation() {
	cout << "Subsystem2::Operation()" << endl;
}

Facade::Facade() {
	this->_sub1 = new Subsystem1();
	this->_sub2 = new Subsystem2();
	cout << "Facade object constructed..." << endl;
}

Facade::~Facade() {
	delete this->_sub1;
	delete this->_sub2;
	cout << "Facade object destructed...." << endl;
}

void Facade::OperationWrapper() {
	this->_sub1->Operation();
	this->_sub1->Operation();
}
