test: main.o Adapter.o
	g++ main.o Adapter.o -o test
main.o:
	g++ main.cpp -c
Adapter.o: Adapter.h
	g++ Adapter.cpp -c
clean:
	rm -f *.o test
