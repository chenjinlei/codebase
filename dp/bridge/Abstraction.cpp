#include "Abstraction.h"
#include "AbstractionImp.h"

#include <iostream>
using namespace std;

Abstraction::Abstraction() {
	cout << "Abstraction constructed..." << endl;
}

Abstraction::~Abstraction() {
	cout << "Abstraction destructed..." << endl;
}

RefinedAbstraction::RefinedAbstraction(AbstractionImp *imp) {
	this->_imp = imp;
}

RefinedAbstraction::~RefinedAbstraction() {
	cout << "RefinedAbstraction destructed..." << endl;
}

void RefinedAbstraction::Operation() {
	this->_imp->Operation();
}
