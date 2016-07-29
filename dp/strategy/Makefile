test: main.o Strategy.o Context.o
	g++ main.o Strategy.o Context.o -o test
main.o:
	g++ main.cpp -c
Strategy.o: Strategy.h
	g++ Strategy.cpp -c
Context.o: Context.h
	g++ Context.cpp -c
clean:
	rm -f *.o test
