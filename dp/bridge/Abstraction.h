#ifndef _ABSTRACTION_H
#define _ABSTRACTION_H

class AbstractionImp;

class Abstraction {
	public:
		virtual ~Abstraction();
		virtual void Operation() = 0;
	protected:
		Abstraction();
	private:

};

class RefinedAbstraction : public Abstraction {
	public:
		RefinedAbstraction(AbstractionImp *imp);
		~RefinedAbstraction();
		void Operation();
	protected:

	private:
		AbstractionImp *_imp;
};

#endif
