#ifndef __CURSOR_H_INCLUDED__
#define __CURSOR_H_INCLUDED__

class Cursor {
  public:
    Cursor(int n, int m) {
      cy = n;
      cx = m;
    }
    Cursor(int n) {
      cy = n;
      cx = 1;
    }
    Cursor() {
      cy = 1;
      cx = 1;
    }

    int cy;
    int cx;

    void down();
    void inspect();
    void left();
    void render();
    void right();
    void up();
};

#endif