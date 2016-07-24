#include "Adapter.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	Adaptee *ade = new Adaptee();
	Adapter *apt = new Adapter(ade);

	apt->Request();

	return 0;
}
