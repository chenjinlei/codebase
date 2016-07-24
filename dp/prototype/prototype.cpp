#include "prototype.h"

#include <iostream>
using namespace std;

Prototype::Prototype() {
	cout << "Prototype constructed..." << endl;
}

Prototype::~Prototype() {
	cout << "Prototype destructed..." << endl;
}

Prototype *Prototype::Clone() const {
	return 0;
}

ConcretePrototype::ConcretePrototype() {
	cout << "ConcretePrototype constructed..." << endl;
}

ConcretePrototype::~ConcretePrototype() {
	cout << "ConcretePrototype destructed..." << endl;
}

ConcretePrototype::ConcretePrototype(const ConcretePrototype &cp) {
	cout << "ConcretePrototype copied..." << endl;
}

Prototype *ConcretePrototype::Clone() const {
	return new ConcretePrototype(*this);
}
