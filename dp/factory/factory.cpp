#include <iostream>
#include "factory.h"
#include "product.h"
using namespace std;

Factory::Factory() {
	cout << "Factory constructed..." << endl;
}

Factory::~Factory() {
	cout << "Factory destructed..." << endl;
}

ConcreteFactory::ConcreteFactory() {
	cout << "ConcreteFactory constructed..." << endl;
}

ConcreteFactory::~ConcreteFactory() {
	cout << "ConcreteFactory destructed..." << endl;
}

Product *ConcreteFactory::CreateProduct() {
	// PATT
	return new ConcreteProduct();
}
