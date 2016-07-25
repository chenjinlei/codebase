test: main.o Decorator.o
	g++ main.o Decorator.o -o test
main.o:
	g++ main.cpp -c
Decorator.o: Decorator.h
	g++ Decorator.cpp -c
clean:
	rm -f *.o test
