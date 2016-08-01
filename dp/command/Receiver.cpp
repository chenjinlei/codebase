#include "Receiver.h"

#include <iostream>
using namespace std;

Receiver::Receiver() {
	cout << "Receiver::Receiver()" << endl;
}

Receiver::~Receiver() {
	cout << "Receiver::~Receiver()" << endl;
}

void Receiver::Action() {
	cout << "Receiver action...." << endl;
}
