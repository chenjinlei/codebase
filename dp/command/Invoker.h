#ifndef _INVOKER_H
#define _INVOKER_H

class Command;

class Invoker {
	public:
		Invoker(Command *cmd);
		~Invoker();
		void Invoke();
	protected:

	private:
		Command *_cmd;
};

#endif
