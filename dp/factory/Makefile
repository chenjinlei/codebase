test: factory.o product.o main.o
	g++ main.o factory.o product.o -o test
factory.o: factory.h
	g++ factory.cpp -c
product.o: product.h
	g++ product.cpp -c
main.o:
	g++ main.cpp -c
clean:
	rm -f *.o test
