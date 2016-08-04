#ifndef _ITERATOR_H
#define _ITERATOR_H

class Aggregate;

typedef int Object;

class Iterator {
	public:
		virtual ~Iterator();
		virtual void First() = 0;
		virtual void Next() = 0;
		virtual bool IsDone() = 0;
		virtual Object CurrentItem() = 0;
	protected:
		Iterator();
	private:

};

class ConcreteIterator : public Iterator {
	public:
		ConcreteIterator(Aggregate *agr, int index = 0);
		~ConcreteIterator();
		void First();
		void Next();
		bool IsDone();
		Object CurrentItem();
	protected:

	private:
		Aggregate *_ag;
		int _idx;
};

#endif
