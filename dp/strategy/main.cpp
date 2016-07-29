#include "Context.h"
#include "Strategy.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	Strategy *stg1 = new ConcreteStrategyA();
	Strategy *stg2 = new ConcreteStrategyB();
	Context *con1 = new Context(stg1);
	Context *con2 = new Context(stg2);

	con1->DoSomething();
	con2->DoSomething();

	if (NULL != con1)
		delete con1;

	if (NULL != con2)
		delete con2;

	return 0;
}
