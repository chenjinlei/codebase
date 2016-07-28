test: main.o Facade.o
	g++ main.o Facade.o -o test
main.o:
	g++ main.cpp -c
Facade.o: Facade.h
	g++ Facade.cpp -c
clean:
	rm -f *.o test
