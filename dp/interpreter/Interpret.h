#ifndef _INTERPRET_H
#define _INTERPRET_H

#include "Context.h"
#include <string>
using namespace std;

class AbstractExpression {
	public:
		virtual ~AbstractExpression();
		virtual void Interpret(const Context &con);
	protected:
		AbstractExpression();
	private:

};

class TerminalExpression : public AbstractExpression {
	public:
		TerminalExpression(const string &statement);
		~TerminalExpression();
		void Interpret(const Context &con);
	protected:

	private:
		string _statement;
};

class NonTerminalExpression : public AbstractExpression {
	public:
		NonTerminalExpression(AbstractExpression *expression, int times);
		~NonTerminalExpression();
		void Interpret(const Context &con);
	protected:

	private:
		AbstractExpression *_exptression;
		int _times;
};

#endif
