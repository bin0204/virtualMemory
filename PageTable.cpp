#include "PageTableEntry.h"
#include "PageTable.h"
#include <iostream>
#include <cstddef>

using namespace std;

void PageTable::setPTE(int pt, PageTableEntry *ptr) {
  entries[pt] = ptr;
}

PageTableEntry* PageTable::getPTE(int page) {
  return entries[page];
}

PageTable::PageTable() {

}
