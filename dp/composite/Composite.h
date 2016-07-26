#ifndef _COMPOSITE_H
#define _COMPOSITE_H

#include "Component.h"
#include <vector>
using namespace std;

class Composite : public Component {
	public:
		Composite();
		~Composite();
		void Operation();
		void Add(Component *com);
		void Remove(Component *com);
		Component *GetChild(int index);
	protected:

	private:
		vector<Component*> comVec;
};

#endif
