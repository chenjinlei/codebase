test: Flyweight.o FlyweightFactory.o main.o
	g++ Flyweight.o FlyweightFactory.o main.o -o test
main.o:
	g++ main.cpp -c
Flyweight.o: Flyweight.h
	g++ Flyweight.cpp -c
FlyweightFactory.o: FlyweightFactory.h
	g++ FlyweightFactory.cpp -c
clean:
	rm -f *.o test
