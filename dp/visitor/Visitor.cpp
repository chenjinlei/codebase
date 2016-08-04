#include "Visitor.h"
#include "Element.h"

#include <iostream>
using namespace std;

Visitor::Visitor() {
	cout << "Visitor::Visitor()" << endl;
}

Visitor::~Visitor() {
	cout << "Visitor::~Visitor()" << endl;
}

ConcreteVisitorA::ConcreteVisitorA() {
	cout << "ConcreteVisitorA::ConcreteVisitorA()" << endl;
}

ConcreteVisitorA::~ConcreteVisitorA() {
	cout << "ConcreteVisitorA::ConcreteVisitorA()" << endl;
}

void ConcreteVisitorA::VisitConcreteElementA(Element *elm) {
	cout << "\"I'm visiting ConcreteElementA.\", said ConcreteVisitorA." << endl;
}

void ConcreteVisitorA::VisitConcreteElementB(Element *elm) {
	cout << "\"I'm visiting ConcreteElementB.\", said ConcreteVisitorA." << endl;
}

ConcreteVisitorB::ConcreteVisitorB() {
	cout << "ConcreteVisitorB::ConcreteVisitorB()" << endl;
}

ConcreteVisitorB::~ConcreteVisitorB() {
	cout << "ConcreteVisitorB::~ConcreteVisitorB()" << endl;
}

void ConcreteVisitorB::VisitConcreteElementA(Element *elm) {
	cout << "\"I'm visiting ConcreteElementA.\", said ConcreteVisitorB.";
}

void ConcreteVisitorB::VisitConcreteElementB(Element *elm) {
	cout << "\"I'm visiting ConcreteElementB.\", said ConcreteVisitorB.";
}
