#include "PageTableEntry.h"
#include "PageTable.h"

int PageTableEntry::getFrame() {
  return frame;
}

void PageTableEntry::setFrame(int f) {
  frame = f;
}

bool PageTableEntry::isInMemory() {
  return inMemory; //or true
}

void PageTableEntry::swapToDisk(int diskFrame) {
  inMemory = false;
}

void PageTableEntry::swapToMemory(int memFrame) {
  inMemory = true;
}

PageTableEntry::PageTableEntry() {
  frame = 0;
}
