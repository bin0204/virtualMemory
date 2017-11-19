#include "Memory.h"
#include "PageTableEntry.h"
#include <cstddef> //utility library

static int nextFrame = 0;

void Memory::setFrame(int frame, PageTableEntry *pte) {
  pte -> setFrame(frame);
  pte -> swapToMemory(frame);
  frames[frame] = pte;
}

PageTableEntry* Memory::getFrame(int frame) {
  return frames[frame];
}

int Memory::getFreeFrame() {
  if (frames[nextFrame] != NULL) {
    frames[nextFrame] -> swapToDisk(30);
    frames[nextFrame] = NULL;
  }
  int n = nextFrame;
  nextFrame = (nextFrame + 1) % 30;
  return n;
}


int Memory::findSwapPage() {
  return 0;
}

int Memory::convert(int frame) {
  return 0;
}

Memory::Memory() {

}
