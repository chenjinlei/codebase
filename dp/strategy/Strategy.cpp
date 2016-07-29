#include "Strategy.h"

#include <iostream>
using namespace std;

Strategy::Strategy() {
	cout << "Strategy() called..." << endl;
}

Strategy::~Strategy() {
	cout << "~Strategy() called..." << endl;
}

ConcreteStrategyA::ConcreteStrategyA() {
	cout << "ConcreteStrategyA object constructed..." << endl;
}

ConcreteStrategyA::~ConcreteStrategyA() {
	cout << "ConcreteStrategyA object destructed..." << endl;
}

void ConcreteStrategyA::AlgorithmInterface() {
	cout << "ConcreteStrategyA::AlgorithmInterface()" << endl;
}

ConcreteStrategyB::ConcreteStrategyB() {
	cout << "ConcreteStrategyB object constructed..." << endl;
}

ConcreteStrategyB::~ConcreteStrategyB() {
	cout << "ConcreteStrategyB object destructed..." << endl;
}

void ConcreteStrategyB::AlgorithmInterface() {
	cout << "ConcreteStrategyB::AlgorithmInterface()" << endl;
}
