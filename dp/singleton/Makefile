test: Singleton.o main.o
	g++ main.o Singleton.o -o test
Singleton.o: Singleton.h
	g++ Singleton.cpp -c
main.o:
	g++ main.cpp -c
clean:
	rm -f *.o test
