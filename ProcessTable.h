#include "PageTable.h"

class ProcessTable {
  private:
    PageTable *procPageTable[N];
  public:
    void setProcPT(int pid, PageTable *pt);
    PageTable * getProcPT(int pid);
    inline ProcessTable();
};
