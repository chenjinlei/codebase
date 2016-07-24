#include "prototype.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	Prototype *proto = new ConcretePrototype();
	
	Prototype *clone = proto->Clone();

	return 0;
}
