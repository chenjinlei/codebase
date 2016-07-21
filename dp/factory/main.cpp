#include "factory.h"
#include "product.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	Factory *fac = new ConcreteFactory();
	Product *pro = fac->CreateProduct();

	return 0;
}
