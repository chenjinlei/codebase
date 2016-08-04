#include "Iterator.h"
#include "Aggregate.h"

#include <iostream>
using namespace std;

Iterator::Iterator() {
	cout << "Iterator::Iterator()" << endl;
}

Iterator::~Iterator() {
	cout << "Iterator::~Iterator()" << endl;
}

ConcreteIterator::ConcreteIterator(Aggregate *agr, int index) {
	this->_ag = agr;
	this->_idx = index;
}

ConcreteIterator::~ConcreteIterator() {
	cout << "ConcreteIterator::~ConcreteIterator()" << endl;
}

void ConcreteIterator::First() {
	this->_idx = 0;
}

void ConcreteIterator::Next() {
	if (this->_idx < this->_ag->GetSize())
		++this->_idx;
}

bool ConcreteIterator::IsDone() {
	return this->_idx == this->_ag->GetSize();
}

Object ConcreteIterator::CurrentItem() {
	return this->_ag->GetItem(this->_idx);
}
