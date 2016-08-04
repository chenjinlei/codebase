#include "Aggregate.h"
#include "Iterator.h"

#include <iostream>
using namespace std;

Aggregate::Aggregate() {
	cout << "Aggregate::Aggregate()" << endl;
}

Aggregate::~Aggregate() {
	cout << "Aggregate::~Aggregate()" << endl;
}

ConcreteAggregate::ConcreteAggregate() {
	for (int i = 0; i < SIZE; ++i)
		_obj[i] = i;
	cout << "ConcreteAggregate::ConcreteAggregate()" << endl;
}

ConcreteAggregate::~ConcreteAggregate() {
	cout << "ConcreteAggregate::~ConcreteAggregate()" << endl;
}

Iterator *ConcreteAggregate::CreateIterator() {
	return new ConcreteIterator(this);
}

Object ConcreteAggregate::GetItem(int index) {
	if (index < this->GetSize())
		return _obj[index];
	else
		return -1;
}

int ConcreteAggregate::GetSize() {
	return SIZE;
}
