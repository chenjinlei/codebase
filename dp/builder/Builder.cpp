#include "Product.h"
#include "Builder.h"

#include <iostream>
using namespace std;

Builder::Builder() {
	cout << "Builder constructed..." << endl;
}

Builder::~Builder() {
	cout << "Builder destructed..." << endl;
}

ConcreteBuilder::ConcreteBuilder() {
	cout << "ConcreteBuilder constructed..." << endl;
}

ConcreteBuilder::~ConcreteBuilder() {
	cout << "ConcreteBuilder destructed..." << endl;
}

void ConcreteBuilder::BuildPartA(const string &buildPar) {
	cout << "Step#1: Build Part A..." << buildPar << endl;
}

void ConcreteBuilder::BuildPartB(const string &buildPar) {
	cout << "Step#2: Build Part B..." << buildPar << endl;
}

void ConcreteBuilder::BuildPartC(const string &buildPar) {
	cout << "Step#3: Build Part C..." << buildPar << endl;
}

Product *ConcreteBuilder::GetProduct() {
	this->BuildPartA("pre-defined");
	this->BuildPartB("pre-defined");
	this->BuildPartC("pre-defined");
	return new Product();

}
