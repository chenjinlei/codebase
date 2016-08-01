#include "Memento.h"

#include <string>
#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
	Originator *org = new Originator();

	org->SetState("Old");
	org->PrintState();

	Memento *mem = org->CreateMemento();

	org->SetState("new");
	org->PrintState();

	org->RestoreToMemento(mem);
	org->PrintState();

	return 0;
}
