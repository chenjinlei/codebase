#include "Visitor.h"
#include "Element.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	Visitor *vis = new ConcreteVisitorA();
	Element *elm = new ConcreteElementB();

	elm->Accept(vis);

	return 0;
}
