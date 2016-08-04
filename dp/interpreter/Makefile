test: main.o Context.o Interpret.o
	g++ main.o Context.o Interpret.o -o test
main.o:
	g++ main.cpp -c
Interpret.o: Interpret.h
	g++ Interpret.cpp -c
Context.o: Context.h
	g++ Context.cpp -c
clean:
	rm -f *.o test
