#include "Facade.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	Facade *facade = new Facade();
	
	facade->OperationWrapper();

	return 0;
}
