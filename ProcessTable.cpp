#include "ProcessTable.h"
#include "PageTable.h"

void ProcessTable::setProcPT(int pid, PageTable *pt) {
    procPageTable[pid] = pt;
}

PageTable* ProcessTable::getProcPT(int pid) {
  return procPageTable[pid];
}

ProcessTable::ProcessTable() {

}
