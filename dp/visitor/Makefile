test: main.o Visitor.o Element.o 
	g++ main.o Visitor.o Element.o -o test
main.o:
	g++ main.cpp -c
Visitor.o: Visitor.h
	g++ Visitor.cpp -c
Element.o: Element.h
	g++ Element.cpp -c
clean:
	rm -f *.o test
