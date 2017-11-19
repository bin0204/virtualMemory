#ifndef PAGETABLENTRY_H
#define PAGETABLENTRY_H

class PageTableEntry {
  private:
    bool inMemory;
    int frame;
  public:
    int getFrame();
    void setFrame(int frame);
    bool isInMemory();
    void swapToMemory(int memFrame);
    void swapToDisk(int diskFrame);
    PageTableEntry();
};
#endif
