#include "Leaf.h"

#include <iostream>
using namespace std;

Leaf::Leaf() {
	cout << "Leaf constructed..." << endl;
}

Leaf::~Leaf() {
	cout << "Leaf destructed..." << endl;
}

void Leaf::Operation() {
	cout << "Leaf::Operation" << endl;
}
