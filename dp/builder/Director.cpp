#include "Builder.h"
#include "Director.h"

#include <iostream>
using namespace std;

Director::Director(Builder *builder) {
	this->_builder = builder;
	cout << "Director constructed..." << endl;
}

Director::~Director() {
	cout << "Director destructed..." << endl;
}

void Director::Construct() {
	this->_builder->BuildPartA("user-defined");
	this->_builder->BuildPartB("user-defined");
	this->_builder->BuildPartC("user-defined");
}
