#include "AbstractFactory.h"
#include "Product.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	AbstractFactory *abf1 = new ConcreteFactory1();
	abf1->CreateProductA();
	abf1->CreateProductB();

	AbstractFactory *abf2 = new ConcreteFactory2();
	abf2->CreateProductA();
	abf2->CreateProductB();

	return 0;
}
