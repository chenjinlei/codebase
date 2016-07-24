#include "Adapter.h"

#include <iostream>
using namespace std;

Target::Target() {
	cout << "Target constructed..." << endl;
}

Target::~Target() {
	cout << "Target destructed..." << endl;
}

void Target::Request() {
	cout << "Target::Request" << endl;
}

Adaptee::Adaptee() {
	cout << "Adaptee constructed..." << endl;
}

Adaptee::~Adaptee() {
	cout << "Adaptee destructed..." << endl;
}

void Adaptee::SpecificRequest() {
	cout << "Adaptee::SpecificRequest" << endl;
}

Adapter::Adapter(Adaptee *ade) {
	this->_ade = ade;
	cout << "Adapter constructed..." << endl;
}

Adapter::~Adapter() {
	cout << "Adapter destructed..." << endl;
}

void Adapter::Request() {
	this->_ade->SpecificRequest();
}
