#include "Context.h"
#include "Strategy.h"

#include <iostream>
using namespace std;

Context::Context(Strategy *stg) {
	this->_stg = stg;
	cout << "Context constructed..." << endl;
}

Context::~Context() {
	if (!this->_stg)
		delete this->_stg;

	cout << "Context destructed..." << endl;
}

void Context::DoSomething() {
	this->_stg->AlgorithmInterface();
}
