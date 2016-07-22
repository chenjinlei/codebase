#include "Builder.h"
#include "Director.h"

#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
	Builder *bld = new ConcreteBuilder();
	Director *dir = new Director(bld);

	dir->Construct();

	return 0;
}
