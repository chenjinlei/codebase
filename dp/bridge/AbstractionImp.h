#ifndef _ABSTRACTIONIMP_H
#define _ABSTRACTIONIMP_H

class AbstractionImp {
	public:
		virtual ~AbstractionImp();
		virtual void Operation();
	protected:
		AbstractionImp();
	private:

};

class ConcreteAbstractionImpA : public AbstractionImp {
	public:
		ConcreteAbstractionImpA();
		~ConcreteAbstractionImpA();
		virtual void Operation();
	protected:

	private:

};

class ConcreteAbstractionImpB : public AbstractionImp {
	public:
		ConcreteAbstractionImpB();
		~ConcreteAbstractionImpB();
		virtual void Operation();
	protected:

	private:

};

#endif
