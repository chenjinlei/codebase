test: main.o State.o Context.o
	g++ main.o State.o Context.o -o test
main.o:
	g++ main.cpp -c
State.o: State.h
	g++ State.cpp -c
Context.o: Context.h
	g++ Context.cpp -c
clean:
	rm -f *.o test
