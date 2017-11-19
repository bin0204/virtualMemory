#ifndef PAGETABLE_H
#define PAGETABLE_H

#include "PageTableEntry.h"

class PageTable {
  private:
    PageTableEntry *entries[64];
  public:
    void setPTE(int pt, PageTableEntry *ptr);
    PageTableEntry * getPTE(int page);
    PageTable();
};

#endif
