#include "Template.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	AbstractClass *abc1 = new ConcreteClass1();
	AbstractClass *abc2 = new ConcreteClass2();

	abc1->TemplateMethod();
	abc2->TemplateMethod();

	return 0;
}
