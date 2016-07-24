#include "AbstractionImp.h"

#include <iostream>
using namespace std;

AbstractionImp::AbstractionImp() {
	cout << "AbstractionImp constructed..." << endl;
}

AbstractionImp::~AbstractionImp() {
	cout << "AbstractionImp destructed...." << endl;
}

void AbstractionImp::Operation() {
	cout << "AbstractionImp...imp..." << endl;
}

ConcreteAbstractionImpA::ConcreteAbstractionImpA() {
	cout << "ConcreteAbstractionImpA constructed...." << endl;
}

ConcreteAbstractionImpA::~ConcreteAbstractionImpA() {
	cout << "ConcreteAbstractionImpA destructed..." << endl;
}

void ConcreteAbstractionImpA::Operation() {
	cout << "ConcreteAbstractionImpA...imp..." << endl;
}

ConcreteAbstractionImpB::ConcreteAbstractionImpB() {
	cout << "ConcreteAbstractionImpB constructed..." << endl;
}

ConcreteAbstractionImpB::~ConcreteAbstractionImpB() {
	cout << "ConcreteAbstractionImpB destructed..." << endl;
}

void ConcreteAbstractionImpB::Operation() {
	cout << "ConcreteAbstractionImpB...imp..." << endl;
}
