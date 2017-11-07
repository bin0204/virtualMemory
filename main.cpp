#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
void accessMemory(string);
void newProcess(string);
void switchProcess(string);

int main() {

  //Open a file for reading
  ifstream file("VMInput.txt");
  //Store a string by line
  string line;
  //getline for reading strings is useful if you suspect
  //that you will have longer lines, since strings are dynamically allocated
  //this getline is implemented as a global function instead of as
  //member of the stream class
  while(getline(file,line)) {
    //COMMAND : new, switch, access
    //number(value) : pid (memory location)
    //new : create a new process (pid)
    //new 1
    //switch : switch to run a different process (pid)
    //switch 1
    //access : access memory (memory)
    //access 45298

    //istringtream uses delim to string to parsing
    istringstream charFromStream(line);
    string command;
    string number;
    //getline(char *s, streamsize n, char delim)
    getline(charFromStream, command, ' ');
    getline(charFromStream, number, ' ');
    if (command == "new"){
      newProcess(number);
    }
    else if (command == "switch") {
      switchProcess(number);
    }
    else {
      accessMemory(number);
    }


  }
}
