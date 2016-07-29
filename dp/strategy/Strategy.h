#ifndef _STRATEGY_H
#define _STRATEGY_H

class Strategy {
	public:
		Strategy();
		virtual ~Strategy();
		virtual void AlgorithmInterface() = 0;
	protected:

	private:

};

class ConcreteStrategyA : public Strategy {
	public:
		ConcreteStrategyA();
		virtual ~ConcreteStrategyA();
		void AlgorithmInterface();
	protected:

	private:

};

class ConcreteStrategyB : public Strategy {
	public:
		ConcreteStrategyB();
		virtual ~ConcreteStrategyB();
		void AlgorithmInterface();
	protected:

	private:

};

#endif
