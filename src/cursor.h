#ifndef __CURSOR_H_INCLUDED__
#define __CURSOR_H_INCLUDED__

class Cursor {
  int tmp_cx;
  int tmp_cy;

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

    // Moves the cursor down by one line.
    void down();

    void inspect();

    // Moves the cursor left by one character.
    void left();
    void render();
    void restore();

    // Moves the cursor right by one character.
    void right();
    void store();

    // Moves the cursor up by one line.
    void up();
};

#endif