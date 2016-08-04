test: main.o Aggregate.o Iterator.o
	g++ main.o Aggregate.o Iterator.o -o test
main.o:
	g++ main.cpp -c
Aggregate.o: Aggregate.h
	g++ Aggregate.cpp -c
Iterator.o: Iterator.h
	g++ Iterator.cpp -c
clean:
	rm -f *.o test
