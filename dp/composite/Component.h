#ifndef _COMPONENT_H
#define _COMPONENT_H

class Component {
	public:
		Component();
		virtual ~Component();
		virtual void Operation() = 0;
		virtual void Add(const Component &);
		virtual void Remove(const Component &);
		virtual Component *GetChild(int );
	protected:

	private:

};

#endif
