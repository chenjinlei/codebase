#include "Decorator.h"

#include <iostream>
using namespace std;

Component::Component() {
	cout << "Component constructed..." << endl;
}

Component::~Component() {
	cout << "Component destructed..." << endl;
}

void Component::Operation() {
	cout << "Component::Operation" << endl;
}

ConcreteComponent::ConcreteComponent() {
	cout << "ConcreteComponent constructed..." << endl;
}

ConcreteComponent::~ConcreteComponent() {
	cout << "ConcreteComponent destructed..." << endl;
}

void ConcreteComponent::Operation() {
	cout << "ConcreteComponent::Operation" << endl;
}

Decorator::Decorator(Component *com) {
	this->_com = com;
	cout << "Decorator constructed..." << endl;
}

Decorator::~Decorator() {
	cout << "Decorator destructed..." << endl;
}

void Decorator::Operation() {
	this->_com->Operation();
}

ConcreteDecorator::ConcreteDecorator(Component *com) : Decorator(com) {
	cout << "ConcreteDecorator constructed..." << endl;
}

ConcreteDecorator::~ConcreteDecorator() {
	cout << "ConcreteDecorator destructed..." << endl;
}

void ConcreteDecorator::Operation() {
	this->_com->Operation();
	this->AddedBehavior();
}

void ConcreteDecorator::AddedBehavior() {
	cout << "ConcreteDecorator::AddedBehavior" << endl;
}
