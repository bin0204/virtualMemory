all: virtualMemory

virtualMemory : main.o Disk.o Memory.o PageTable.o PageTableEntry.o ProcessTable.o
		g++ -c -Wall main.o -o virtualMemory

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
		
Disk.o: Disk.cpp
				g++ -c -Wall Disk.cpp


clean:
		rm -f *.o
