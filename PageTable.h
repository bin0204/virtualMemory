#include "PageTableEntry.h"

class PageTable {
  private:
    PageTableEntry *entries[64];
  public:
    void setPTE(int pt, PageTableEntry *pt);
    PageTableEntry * getPTE(int page);
    inline PageTable();
};
