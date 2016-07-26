#include "Flyweight.h"

#include <iostream>
using namespace std;

Flyweight::Flyweight(string intrinsicState) {
	this->_intrinsicState = intrinsicState;
	cout << "Flyweight constructed..." << endl;
}

Flyweight::~Flyweight() {
	cout << "Flyweight destructed..." << endl;
}

string Flyweight::GetInrinsicState() {
	return this->_intrinsicState;
}

void Flyweight::Operation(const string &extrinsicState) {
	cout << "Flyweight::Operation" << endl;
	cout << "Flyweight::extrinsicState[" << extrinsicState << "]" << endl;
}


ConcreteFlyweight::ConcreteFlyweight(string intrinsicState) : Flyweight(intrinsicState) {
	cout << "ConcreteFlyweight constructed..." << endl;
}

ConcreteFlyweight::~ConcreteFlyweight() {
	cout << "ConcreteFlyweight destructed..." << endl;
}

void ConcreteFlyweight::Operation(const string &extrinsicState) {
	cout << "ConcreteFlyweight::intrinsicState[" << this->GetInrinsicState()
		<< "]" << endl << "ConcreteFlyweight::extrinsicState[" 
		<< extrinsicState << "]" << endl;
}
