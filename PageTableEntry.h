class PageTableEntry {
  private:
    bool inMemory;
    int frame;
  public:
    int getFrame();
    bool inMemory();
    void swapToMemory(int memFrame);
    void swapToDisk(int diskFrame);
    inline PageTableEntry();
};
