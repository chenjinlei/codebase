#include "Colleage.h"
#include "Mediator.h"

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
	Mediator *md = new ConcreteMediator();
	Colleage *clg1 = new ConcreteColleageA(md);
	Colleage *clg2 = new ConcreteColleageB(md);

	md->IntroColleage(clg1, clg2);
	clg1->SetState("old");
	clg2->SetState("old");
	
	clg1->Action();
	clg2->Action();
	cout << endl;

	clg1->SetState("new");
	clg1->Action();
	clg2->Action();
	cout << endl;

	clg2->SetState("old");
	clg2->Action();
	clg1->Action();


	return 0;

}
