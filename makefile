all: virtualMemory

virtualMemory : main.o
		g++ -c -Wall main.o -o virtualMemory

main.o: main.cpp
		g++ -c -Wall main.cpp

clean:
		rm -f *.o
