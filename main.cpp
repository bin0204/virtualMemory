#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include <bitset>
#include <string>
#include <typeinfo>
#include <stdlib.h>
#include "Memory.h"
#include "PageTableEntry.h"
#include "ProcessTable.h"
#include "PageTable.h"

using namespace std;

void accessMemory(int memoryAddress);
void newProcess(int n);
void switchProcess(int n);

int compulsoryMiss = 0;
int hits = 0;
int miss = 0;
int counter = 0;

PageTable * currentTable;
ProcessTable* processTable;
Memory memory;

int main() {

  //Open a file for reading
  ifstream file("VMInput.txt");
  //Store a string by line
  string line;
  processTable = new ProcessTable();
  //getline for reading strings is useful if you suspect
  //that you will have longer lines, since strings are dynamically allocated
  //this getline is implemented as a global function instead of as
  //member of the stream class
  while(getline(file,line)) {
    istringstream str(line);
    string command; //first value
    string numbers; //second

    getline(str, command, ' ');
    getline(str, numbers, ' ');
    //convert string to (char* to integer)
    int value = atoi(numbers.c_str()); //string to char*

    //COMMAND : new, switch, access
    //number(value) : pid (memory location)
    //new : create a new process (pid)
    //new 1
    //switch : switch to run a different process (pid)
    //switch 1
    //access : access memory (memory)
    //access 45298
    if (command == "new"){
      newProcess(value);
    }
    else if (command == "switch") {
      switchProcess(value);
    }
    else {
      accessMemory(value);
    }
  }
  printf("Access: %d\n", counter);
  printf("Hits: %d\n",hits);
  printf("Misses: %d\n",miss);
  printf("Compulsory Misses: %d\n",compulsoryMiss);
}
void accessMemory(int memoryAddress) {
  counter++;
  int page = memoryAddress >> 10;
  PageTableEntry* pte;
  if (currentTable->getPTE(page) == NULL) {
    pte = new PageTableEntry(); //current one is null then make new page entry
    compulsoryMiss++;
  }
  else {
    pte = currentTable -> getPTE(page);
  }
  if (pte -> isInMemory()) {
    hits++;
  }
  else {
    miss++;
    int freeFrame = memory.getFreeFrame();
    memory.setFrame(freeFrame,pte);
  }
  currentTable -> setPTE(page,pte);
}
//create new process
void newProcess(int n) {
  PageTable* p = new PageTable();
  processTable -> setProcPT(n, p);
}

//which process is in
void switchProcess(int n) {
  currentTable = processTable -> getProcPT(n);
}
