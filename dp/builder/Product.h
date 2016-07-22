#ifndef _PRODUCT_H
#define _PRODUCT_H

class Product {
	public:
		Product();
		~Product();
		void ProducePart();
	protected:

	private:

};

class ProductPart {
	public:
		ProductPart();
		~ProductPart();
		ProductPart *BuildPart();
	protected:

	private:

};

#endif
