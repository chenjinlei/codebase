#ifndef _AGGREGATE_H
#define _AGGREGATE_H

class Iterator;

typedef int Object;

class Aggregate {
	public:
		virtual ~Aggregate();
		virtual Iterator *CreateIterator() = 0;
		virtual Object GetItem(int index) = 0;
		virtual int GetSize() = 0;
	protected:
		Aggregate();
	private:

};

class ConcreteAggregate : public Aggregate {
	public:
		enum {SIZE = 3};
		ConcreteAggregate();
		~ConcreteAggregate();
		Iterator *CreateIterator();
		Object GetItem(int index);
		int GetSize();
	protected:

	private:
		Object _obj[SIZE];
};

#endif
