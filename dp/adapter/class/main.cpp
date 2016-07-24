#include "Adapter.h"

#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
	Target *apt = new Adapter();

	apt->Request();

	return 0;
}
