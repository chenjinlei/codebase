test: main.o Subject.o Observer.o
	g++ main.o Subject.o Observer.o -o test
main.o:
	g++ main.cpp -c
Subject.o: Subject.h
	g++ Subject.cpp -c
Observer.o: Observer.h
	g++ Observer.cpp -c
clean:
	rm -f *.o test
