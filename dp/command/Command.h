#ifndef _COMMAND_H
#define _COMMAND_H

class Receiver;

class Command {
	public:
		virtual ~Command();
		virtual void Execute() = 0;
	protected:
		Command();
	private:

};

class ConcreteCommand : public Command {
	public:
		ConcreteCommand(Receiver *recv);
		~ConcreteCommand();
		void Execute();
	protected:

	private:
		Receiver *_recv;
};

#endif
