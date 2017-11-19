#ifndef PROCESSTABLE_H
#define PROCESSTABLE_H

#include "PageTable.h"

class ProcessTable {
  private:
    PageTable *procPageTable[10];
    int pointer;
  public:
    void setProcPT(int pid, PageTable *pt);
    PageTable * getProcPT(int pid);
    ProcessTable();
};

#endif
