#include "Memento.h"

#include <iostream>
using namespace std;

typedef string State;

Originator::Originator() {
	this->_st = '\0';
	this->_mem = 0;
	cout << "Originator::Originator()" << endl;
}

Originator::Originator(const State &st) {
	this->_st = st;
	this->_mem = 0;
	cout << "Originator::Originator(const State &st)" << endl;
}

Originator::~Originator() {
	cout << "Originator::~Originator()" << endl;
}

Memento *Originator::CreateMemento() {
	return new Memento(this->_st);
}

State Originator::GetState() {
	return this->_st;
}

void Originator::SetState(const State &st) {
	this->_st = st;
}

void Originator::PrintState() {
	cout << "State: " << this->_st << endl;
}

void Originator::SetMemento(Memento *mem) {
	// this->_mem = mem;
}

void Originator::RestoreToMemento(Memento *mem) {
	this->_st = mem->GetState();
}

Memento::Memento() {
	cout << "Memento::Memento()" << endl;
}

Memento::Memento(const State &st) {
	this->_st = st;
	cout << "Memento::Memento()" << endl;
}

Memento::~Memento() {
	cout << "Memento::~Memento()" << endl;
}

State Memento::GetState() {
	return this->_st;
}

void Memento::SetState(const State &st) {
	this->_st = st;
}
