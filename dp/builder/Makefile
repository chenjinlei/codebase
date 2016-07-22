test: main.o Director.o Builder.o Product.o
	g++ main.o Director.o Builder.o Product.o -o test
Product.o: Product.h
	g++ Product.cpp -c
Builder.o: Builder.h
	g++ Builder.cpp -c
Director.o: Director.h
	g++ Director.cpp -c
main.o:
	g++ main.cpp -c
clean:
	rm -f *.o test
