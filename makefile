all: virtualMemory

virtualMemory : main.o Memory.o PageTable.o PageTableEntry.o ProcessTable.o
		g++ main.o Memory.o PageTable.o PageTableEntry.o ProcessTable.o -o virtualMemory

main.o: main.cpp
		g++ -c -Wall main.cpp

Memory.o: Memory.cpp
		g++ -c -Wall Memory.cpp

PageTable.o: PageTable.cpp
		g++ -c -Wall PageTable.cpp

PageTableEntry: PageTableEntry.cpp
		g++ -c -Wall PageTableEntry.cpp

ProcessTable: ProcessTable.cpp
		g++ -c -Wall ProcessTable.cpp

clean:
		rm -f *.o
