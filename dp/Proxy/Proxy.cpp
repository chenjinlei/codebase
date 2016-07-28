#include "Proxy.h"

#include <iostream>
using namespace std;

Subject::Subject() {
	cout << "Subject constructed..." << endl;
}

Subject::~Subject() {
	cout << "Subject destructed..." << endl;
}

ConcreteSubject::ConcreteSubject() {
	cout << "ConcreteSubject object constructed..." << endl;
}

ConcreteSubject::~ConcreteSubject() {
	cout << "ConcreteSubject object destructed..." << endl;
}

void ConcreteSubject::Request() {
	cout << "ConcreteSubject::Request()" << endl;
}

Proxy::Proxy() {
	cout << "Proxy object constructed(default)..." << endl;
}

Proxy::Proxy(Subject *sub) {
	this->_sub = sub;
	cout << "Proxy object constructed..." << endl;
}

Proxy::~Proxy() {
	cout << "Proxy object destructed..." << endl;
}

void Proxy::Request() {
	cout << "Proxy::Request()" << endl;
	this->_sub->Request();
}
