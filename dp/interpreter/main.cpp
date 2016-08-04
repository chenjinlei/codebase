#include "Context.h"
#include "Interpret.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	Context *con = new Context();
	AbstractExpression *te = new TerminalExpression("hello");
	AbstractExpression *nte = new NonTerminalExpression(te, 2);

	nte->Interpret(*con);


	return 0;
}
