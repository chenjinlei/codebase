test: main.o AbstractFactory.o Product.o 
	g++ main.o AbstractFactory.o Product.o -o test
Product.o: Product.h
	g++ Product.cpp -c
AbstractFactory.o: AbstractFactory.h
	g++ AbstractFactory.cpp -c
main.o:
	g++ main.cpp -c
clean:
	rm -f *.o test
