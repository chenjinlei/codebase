#include "Element.h"
#include "Visitor.h"

#include <iostream>
using namespace std;

Element::Element() {
	cout << "Element::Element()" << endl;
}

Element::~Element() {
	cout << "Element::~Element()" << endl;
}

ConcreteElementA::ConcreteElementA() {
	cout << "ConcreteElementA::ConcreteElementA()" << endl;
}

ConcreteElementA::~ConcreteElementA() {
	cout << "ConcreteElementA::~ConcreteElementA()" << endl;
}

void ConcreteElementA::Accept(Visitor *vis) {
	vis->VisitConcreteElementA(this);
	cout << "Visiting ConcreteElementA..." << endl;
}

ConcreteElementB::ConcreteElementB() {
	cout << "ConcreteElementB::ConcreteElementB()" << endl;
}

ConcreteElementB::~ConcreteElementB() {
	cout << "ConcreteElementB::~ConcreteElementB()" << endl;
}

void ConcreteElementB::Accept(Visitor *vis) {
	vis->VisitConcreteElementB(this);
}
