#include "Component.h"
#include "Composite.h"
#include "Leaf.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	Leaf *leaf = new Leaf();
	leaf->Operation();

	Composite *com = new Composite();
	com->Add(leaf);
	com->Operation();

	Component *cop = com->GetChild(0);
	cop->Operation();

	return 0;
}
