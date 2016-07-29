#ifndef _CONTEXT_H
#define _CONTEXT_H

class Strategy;

class Context {
	public:
		virtual ~Context();
		Context(Strategy *stg);
		void DoSomething();
	protected:

	private:
		Strategy *_stg;
};

#endif
