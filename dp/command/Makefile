test: main.o Receiver.o Command.o Invoker.o
	g++ main.o Receiver.o Command.o Invoker.o -o test
main.o:
	g++ main.cpp -c
Receiver.o: Receiver.h
	g++ Receiver.cpp -c
Command.o: Command.h
	g++ Command.cpp -c
Invoker.o: Invoker.h
	g++ Invoker.cpp -c
clean:
	rm -f *.o test
