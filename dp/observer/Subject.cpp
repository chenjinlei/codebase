#include "Subject.h"
#include "Observer.h"

#include <iostream>
#include <list>
using namespace std;

typedef string state;

Subject::Subject() {
	_obvs = new list<Observer *>;
	cout << "Subject::Subject()" << endl;
}

Subject::~Subject() {
	cout << "Subject::~Subject()" << endl;
}

void Subject::Attach(Observer *obv) {
	_obvs->push_front(obv);
}

void Subject::Detach(Observer *obv) {
	if (obv != NULL)
		_obvs->remove(obv);
}

void Subject::Notify() {
	list<Observer *>::iterator it;

	it = _obvs->begin();
	for (; it != _obvs->end(); ++it) {
		(*it)->Update(this);
	}
}

ConcreteSubject::ConcreteSubject() {
	this->_st = '\0';
	cout << "ConcreteSubject object constructed..." << endl;
}

ConcreteSubject::~ConcreteSubject() {
	cout << "ConcreteSubject object destructed..." << endl;
}

State ConcreteSubject::GetState() {
	return this->_st;
}

void ConcreteSubject::SetState(const State &st) {
	this->_st = st;
}
