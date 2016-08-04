#include "Context.h"
#include "Interpret.h"

#include <iostream>
using namespace std;

AbstractExpression::AbstractExpression() {
	cout << "AbstractExpression::AbstractExpression()" << endl;
}

AbstractExpression::~AbstractExpression() {
	cout << "AbstractExpression::~AbstractExpression()" << endl;
}

void AbstractExpression::Interpret(const Context &con) {
	cout << "AbstractExpression::Interpret(con)" << endl;
}

TerminalExpression::TerminalExpression(const string &statement) {
	this->_statement = statement;
	cout << "TerminalExpression::TerminalExpression(statement)" << endl;
}

TerminalExpression::~TerminalExpression() {
	cout << "TerminalExpression::~TerminalExpression()" << endl;
}

void TerminalExpression::Interpret(const Context &con) {
	cout << "TerminalExpression: " << _statement << endl;
}

NonTerminalExpression::NonTerminalExpression(AbstractExpression *expression, int times) {
	this->_exptression = expression;
	this->_times = times;
	cout << "NonTerminalExpression::NonTerminalExpression(expression, times)" << endl;
}

NonTerminalExpression::~NonTerminalExpression() {
	cout << "NonTerminalExpression::~NonTerminalExpression()" << endl;
}

void NonTerminalExpression::Interpret(const Context &con) {
	for (int i = 0; i < this->_times; ++i)
		this->_exptression->Interpret(con);
}
