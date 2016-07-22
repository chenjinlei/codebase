#include "Product.h"

#include <iostream>
using namespace std;

AbstractProductA::AbstractProductA() {
	cout << "AbstractProductA constructed..." << endl;
}

AbstractProductA::~AbstractProductA() {
	cout << "AbstractProductA destructed..." << endl;
}

AbstractProductB::AbstractProductB() {
	cout << "AbstractProductB constructed..." << endl;
}

AbstractProductB::~AbstractProductB() {
	cout << "AbstractProductB destructed..." << endl;
}

ProductA1::ProductA1() {
	cout << "ProductA1 constructed..." << endl;
}

ProductA1::~ProductA1() {
	cout << "ProductA1 destructed..." << endl;
}

ProductA2::ProductA2() {
	cout << "ProductA2 constructed..." << endl;
}

ProductA2::~ProductA2() {
	cout << "ProductA2 destructed..." << endl;
}

ProductB1::ProductB1() {
	cout << "ProductB1 constructed..." << endl;
}

ProductB1::~ProductB1() {
	cout << "ProductB1 destructed..." << endl;
}

ProductB2::ProductB2() {
	cout << "ProductB2 constructed..." << endl;
}

ProductB2::~ProductB2() {
	cout << "ProductB2 destructed..." << endl;
}
