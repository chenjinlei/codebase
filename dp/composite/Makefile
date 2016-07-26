test: main.o Component.o Composite.o Leaf.o
	g++ main.o Component.o Composite.o Leaf.o -o test
main.o:
	g++ main.cpp -c
Component.o: Component.h
	g++ Component.cpp -c
Composite.o: Composite.h
	g++ Composite.cpp -c
Leaf.o: Leaf.h
	g++ Leaf.cpp -c
clean:
	rm -f *.o test
