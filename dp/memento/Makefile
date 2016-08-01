test: main.o Memento.o
	g++ main.o Memento.o -o test
main.o:
	g++ main.cpp -c
Memento.o: Memento.h
	g++ Memento.cpp -c
clean:
	rm -f *.o test
