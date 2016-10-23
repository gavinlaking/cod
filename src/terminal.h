#ifndef __TERMINAL_H_INCLUDED__
#define __TERMINAL_H_INCLUDED__

class Terminal {
  public:
    Terminal() {
      tx = 1;
      ty = 1;
      txn = 90;
      tyn = 25;
    }

    int tx;
    int ty;
    int txn;
    int tyn;
    
    int height();
    void inspect();
    int width();
};

#endif