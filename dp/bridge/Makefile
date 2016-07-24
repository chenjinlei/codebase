test: main.o Abstraction.o AbstractionImp.o
	g++ main.o Abstraction.o AbstractionImp.o -o test
main.o:
	g++ main.cpp -c
Abstraction.o: Abstraction.h
	g++ Abstraction.cpp -c
AbstractionImp.o: AbstractionImp.h
	g++ AbstractionImp.cpp -c
clean:
	rm -f *.o test
