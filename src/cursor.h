#ifndef __CURSOR_H_INCLUDED__
#define __CURSOR_H_INCLUDED__

class Cursor
{
  private:
    int tmp_cx;
    int tmp_cy;

  public:
    Cursor(int n, int m)
    {
      cy = tmp_cy = (n < 0) ? 0 : n;
      cx = tmp_cx = (m < 0) ? 0 : m;
    }

    Cursor(int n)
    {
      cy = tmp_cy = (n < 0) ? 0 : n;
      cx = tmp_cx = 0;
    }

    Cursor()
    {
      cy = tmp_cy = 0;
      cx = tmp_cx = 0;
    }

    int cy;
    int cx;

    // Moves the cursor down by one line.
    int down();

    void inspect();

    // Moves the cursor left by one character.
    int left();

    void position(int n, int m);
    void render();
    void restore();

    // Moves the cursor right by one character.
    int right();
    void store();

    // Moves the cursor up by one line.
    int up();
};

#endif
