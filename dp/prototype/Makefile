test: main.o Prototype.o
	g++ main.o Prototype.o -o test
Prototype.o: Prototype.h
	g++ Prototype.cpp -c
main.o:
	g++ main.cpp -c
clean:
	rm -f *.o test
