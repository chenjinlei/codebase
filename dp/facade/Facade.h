#ifndef _FACADE_H
#define _FACADE_H

class Subsystem1 {
	public:
		Subsystem1();
		~Subsystem1();
		void Operation();
	protected:

	private:

};

class Subsystem2 {
	public:
		Subsystem2();
		~Subsystem2();
		void Operation();
	protected:

	private:

};

class Facade {
	public:
		Facade();
		~Facade();
		void OperationWrapper();
	protected:

	private:
		Subsystem1 *_sub1;
		Subsystem2 *_sub2;
};

#endif
