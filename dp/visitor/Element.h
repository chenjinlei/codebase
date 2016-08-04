#ifndef _ELEMENT_H
#define _ELEMENT_H

class Visitor;

class Element {
	public:
		virtual ~Element();
		virtual void Accept(Visitor *vis) = 0;
	protected:
		Element();
	private:

};

class ConcreteElementA : public Element {
	public:
		ConcreteElementA();
		~ConcreteElementA();
		void Accept(Visitor *vis);
	protected:

	private:

};

class ConcreteElementB : public Element {
	public:
		ConcreteElementB();
		~ConcreteElementB();
		void Accept(Visitor *vis);
	protected:

	private:

};

#endif
