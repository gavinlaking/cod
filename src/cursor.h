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

    // Move the cursor to the last line.
    // TODO: Should this be the last line of the terminal or the
    //   current buffer?
    int bottom();

    // Moves the cursor down by one line.
    int down();

    void inspect();

    // Moves the cursor left by one character.
    int left();
    int leftmost();

    void position(int n, int m);
    void render();
    void restore();

    // Moves the cursor right by one character.
    int right();

    // Moves the cursor to the last column.
    // TODO: Should this be the last column of the terminal or the
    //   current buffer?
    int rightmost();
    void store();

    // Moves the cursor to the first line.
    int top();

    // Moves the cursor up by one line.
    int up();
};

#endif
