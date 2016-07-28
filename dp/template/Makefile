test: main.o Template.o
	g++ main.o Template.o -o test
main.o:
	g++ main.cpp -c
Template.o: Template.h
	g++ Template.cpp -c
clean:
	rm -f *.o test
