#include <iostream>
#include "product.h"
using namespace std;

Product::Product()
{
	cout << "Product constructed..." << endl;
}

Product::~Product()
{
	cout << "Product destructed..." << endl;
}

ConcreteProduct::ConcreteProduct()
{
	cout << "ConcreteProduct constructed..." << endl;
}

ConcreteProduct::~ConcreteProduct()
{
	cout << "ConcreteProduct destructed..." << endl;
}

