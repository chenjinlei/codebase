#include "AbstractionImp.h"
#include "Abstraction.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	AbstractionImp *imp = new ConcreteAbstractionImpA();
	Abstraction *abs = new RefinedAbstraction(imp);

	abs->Operation();

	return 0;
}
