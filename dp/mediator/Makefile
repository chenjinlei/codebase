test: main.o Mediator.o Colleage.o
	g++ main.o Mediator.o Colleage.o -o test
main.o:
	g++ main.cpp -c
Mediator.o: Mediator.h
	g++ Mediator.cpp -c
Colleage.o: Colleage.h
	g++ Colleage.cpp -c
clean:
	rm -f *.o test
