#include "Product.h"

#include <iostream>
using namespace std;

Product::Product() {
	ProducePart();
	cout << "Product constructed..." << endl;
}

Product::~Product() {
	cout << "Product destructed..." << endl;
}

void Product::ProducePart() {
	cout << "Build part of product." << endl;
}


ProductPart::ProductPart() {
	cout << "ProductPart constructed..." << endl;
}

ProductPart::~ProductPart() {
	cout << "ProductPart destructed..." << endl;
}

ProductPart *ProductPart::BuildPart() {
	return new ProductPart();
}

