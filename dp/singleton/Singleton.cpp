#include "Singleton.h"

#include <iostream>
using namespace std;

Singleton *Singleton::_instance = 0;

Singleton::Singleton() {
	cout << "Singleton constructed..." << endl;
}

Singleton *Singleton::getInstance() {
	if (0 == _instance) {
		_instance = new Singleton();
	}
	
	return _instance;
}
