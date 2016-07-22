#include "AbstractFactory.h"
#include "Product.h"

#include <iostream>
using namespace std;

AbstractFactory::AbstractFactory() {
	cout << "AbstractFactory constructed..." << endl;
}

AbstractFactory::~AbstractFactory() {
	cout << "AbstractFactory destructed..." << endl;
}

ConcreteFactory1::ConcreteFactory1() {
	cout << "ConcreteFactory1 constructed..." << endl;
}

ConcreteFactory1::~ConcreteFactory1() {
	cout << "ConcreteFactory1 destructed..." << endl;
}

AbstractProductA *ConcreteFactory1::CreateProductA() {
	return new ProductA1();
}

AbstractProductB *ConcreteFactory1::CreateProductB() {
	return new ProductB1();
}

ConcreteFactory2::ConcreteFactory2() {
	cout << "ConcreteFactory2 constructed..." << endl;
}

ConcreteFactory2::~ConcreteFactory2() {
	cout << "ConcreteFactory2 destructed..." << endl;
}

AbstractProductA *ConcreteFactory2::CreateProductA() {
	return new ProductA2();
}

AbstractProductB *ConcreteFactory2::CreateProductB() {
	return new ProductB2();
}
