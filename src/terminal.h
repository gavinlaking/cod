#ifndef __TERMINAL_H_INCLUDED__
#define __TERMINAL_H_INCLUDED__

class Terminal
{
  void init();

  public:
    Terminal()
    {
      tx = 1;
      ty = 1;
      txn = 80;
      tyn = 25;
    }

    struct termios oldt, newt;
    int tx;
    int ty;
    int txn;
    int tyn;

    void close();
    int height();
    void inspect();
    void open();
    int width();
};

#endif
