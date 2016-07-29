#include "State.h"
#include "Context.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	State *st = new ConcreteStateA();
	Context *con = new Context(st);

	con->OperationChangeState();
	con->OperationChangeState();
	con->OperationChangeState();

	if (NULL != con)
		delete con;

	if (NULL != st)
		st = NULL;

	return 0;
}
