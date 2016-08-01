#include "Subject.h"
#include "Observer.h"

#include <string>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	Subject *sub = new ConcreteSubject();
	Observer *o1 = new ConcreteObserverA(sub);
	Observer *o2 = new ConcreteObserverB(sub);

	sub->SetState("Old");
	sub->Notify();
	sub->SetState("New");
	sub->Notify();

	return 0;
}
