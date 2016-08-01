#include "Receiver.h"
#include "Command.h"
#include "Invoker.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	Receiver *recv = new Receiver();
	Command *cmd = new ConcreteCommand(recv);
	Invoker *inv = new Invoker(cmd);

	inv->Invoke();

	return 0;
}
