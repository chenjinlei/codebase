#ifndef _PRODUCT_H
#define _PRODUCT_H

class Product {
	public:
		// PATT: pay attention to this;
		virtual ~Product() = 0;
	protected:
		// Hided construction
		Product();
	private:

};

class ConcreteProduct : public Product {
	public:
		~ConcreteProduct();
		ConcreteProduct();
	protected:

	private:

};

#endif
