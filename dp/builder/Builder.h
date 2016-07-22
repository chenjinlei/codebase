#ifndef _BUILDER_H
#define _BUILDER_H

#include <cstring>
#include <iostream>
using namespace std;

class Product;

class Builder {
	public:
		virtual ~Builder();
		virtual void BuildPartA(const string &buildPar) = 0;
		virtual void BuildPartB(const string &buildPar) = 0;
		virtual void BuildPartC(const string &buildPar) = 0;
		virtual Product *GetProduct() = 0;
	protected:
		Builder();
	private:
};

class ConcreteBuilder : public Builder {
	public:
		ConcreteBuilder();
		~ConcreteBuilder();
		void BuildPartA(const string &buildPar);
		void BuildPartB(const string &buildPar);
		void BuildPartC(const string &buildPar);
		Product *GetProduct();
	protected:
		
	private:

};

#endif
