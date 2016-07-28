test: main.o Proxy.o
	g++ main.o Proxy.o -o test
main.o:
	g++ main.cpp -c
Proxy.o: Proxy.h
	g++ Proxy.cpp -c
clean:
	rm -f *.o test
