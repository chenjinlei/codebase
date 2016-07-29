#ifndef _CONTEXT_H
#define _CONTEXT_H

class State;

class Context {
	public:
		Context();
		Context(State *state);
		~Context();
		void OperationInterface();
		void OperationChangeState();
	protected:

	private:
		friend class State;
		bool ChangeState(State *state);
		State *_state;
};

#endif
