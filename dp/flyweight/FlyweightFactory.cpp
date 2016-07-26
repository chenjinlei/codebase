#include "Flyweight.h"
#include "FlyweightFactory.h"

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

FlyweightFactory::FlyweightFactory() {
	cout << "FlyweightFactory constructed..." << endl;
}

FlyweightFactory::~FlyweightFactory() {
	cout << "FlyweightFactory destructed..." << endl;
}

Flyweight *FlyweightFactory::GetFlyweight(const string &key) {
	vector<Flyweight *>::iterator it = _fly.begin();

	for (; it != _fly.end(); ++it) {
		if ((*it)->GetInrinsicState() == key) {
			cout << "[" << key << "] already created by users." << endl;
			return *it;
		}
	}

	Flyweight *fn = new ConcreteFlyweight(key);
	_fly.push_back(fn);

	return fn;
}
