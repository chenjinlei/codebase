#ifndef _DIRECTOR_H
#define _DIRECTOR_H

class Builder;

class Director {
	public:
		Director(Builder *builder);
		~Director();
		void Construct();
	protected:

	private:
		Builder *_builder;
};

#endif
