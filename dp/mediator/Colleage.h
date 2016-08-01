#ifndef _COLLEAGE_H
#define _COLLEAGE_H

#include <string>
using namespace std;

class Mediator;

class Colleage {
	public:
		virtual ~Colleage();
		virtual void Action() = 0;
		virtual void SetState(const string &st) = 0;
		virtual string GetState() = 0;
	protected:
		Colleage();
		Colleage(Mediator *mdt);
		Mediator *_mdt;
	private:

};

class ConcreteColleageA : public Colleage {
	public:
		ConcreteColleageA();
		ConcreteColleageA(Mediator *mdt);
		~ConcreteColleageA();
		void Action();
		void SetState(const string &st);
		string GetState();
	protected:

	private:
		string _st;
};

class ConcreteColleageB : public Colleage {
	public:
		ConcreteColleageB();
		ConcreteColleageB(Mediator *mdt);
		~ConcreteColleageB();
		void Action();
		void SetState(const string &st);
		string GetState();
	protected:

	private:
		string _st;
};

#endif
