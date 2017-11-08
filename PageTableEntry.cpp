#include "PageTableEntry.h"

int PageTableEntry::getFrame() {
  return 0;
}

bool PageTableEntry::inMemory() {
  return false; //or true
}

void PageTableEntry::swapToDisk(int diskFrame) {

}

void PageTableEntry::swapToMemory(int memFrame) {

}

inline PageTableEntry::PageTableEntry() {

}
