test: main.o Handle.o
	g++ main.o Handle.o -o test
main.o:
	g++ main.cpp -c
Handle.o: Handle.h
	g++ Handle.cpp -c
clean:
	rm -f *.o test
