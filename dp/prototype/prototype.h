#ifndef _PROTOTYPE_H
#define _PROTOTYPE_H

class Prototype {
	public:
		virtual ~Prototype();
		virtual Prototype *Clone() const = 0;
	protected:
		Prototype();
	private:

};

class ConcretePrototype : public Prototype {
	public:
		ConcretePrototype();
		~ConcretePrototype();
		ConcretePrototype(const ConcretePrototype &cp);
		Prototype *Clone() const;
	protected:

	private:

};

#endif
