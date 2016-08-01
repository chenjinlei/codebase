#ifndef _MEMENTO_H
#define _MEMENTO_H

#include <string>
using namespace std;

class Memento;

class Originator {
	public:
		typedef string State;
		Originator();
		Originator(const State &st);
		~Originator();
		Memento *CreateMemento();
		void SetMemento(Memento *mem);
		void RestoreToMemento(Memento *mem);
		State GetState();
		void SetState(const State &st);
		void PrintState();
	protected:
	private:
		State _st;
		Memento *_mem;
};

class Memento {
	public:

	protected:

	private:
		friend class Originator;
		typedef string State;
		Memento();
		Memento(const State &st);
		~Memento();
		void SetState(const State &st);
		State GetState();
	private:
		State _st;
};

#endif
