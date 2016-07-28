#include "Proxy.h"

#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
	Subject *sub = new ConcreteSubject();
	Proxy *pro = new Proxy(sub);

	pro->Request();

	return 0;
}
