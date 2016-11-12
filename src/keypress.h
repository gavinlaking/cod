#ifndef __KEYPRESS_H_INCLUDED__
#define __KEYPRESS_H_INCLUDED__

class Keypress {
  int key;
  public:
    Keypress() {}

    int getch();
    void inspect();
};

#endif
