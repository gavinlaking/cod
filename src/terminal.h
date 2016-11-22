#ifndef __TERMINAL_H_INCLUDED__
#define __TERMINAL_H_INCLUDED__

class Terminal
{
  private:
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
    unsigned tx;
    unsigned ty;
    unsigned txn;
    unsigned tyn;

    void close();
    unsigned height();
    void inspect();
    void open();
    void resize();
    unsigned width();
};

#endif
