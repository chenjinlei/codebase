#include "Component.h"
#include "Composite.h"

#include <iostream>
using namespace std;

Composite::Composite() {
	// vector<Component*>::iterator itend = comVec.begin();
	cout << "Composite constructed..." << endl;
}

Composite::~Composite() {
	cout << "Composite destructed..." << endl;
}

void Composite::Operation() {
	vector<Component*>::iterator comIter = comVec.begin();
	for (; comIter != comVec.end(); ++comIter) {
		(*comIter)->Operation();
	}
}

void Composite::Add(Component *com) {
	comVec.push_back(com);
}

void Composite::Remove(Component *com) {
	comVec.erase((vector<Component*>::iterator)&com);
}

Component *Composite::GetChild(int index) {
	return comVec[index];
}
