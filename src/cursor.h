#ifndef __CURSOR_H_INCLUDED__
#define __CURSOR_H_INCLUDED__

class Cursor
{
  private:

  public:
    Cursor(int n, int m)
    {
      cy = (n < 1) ? 1 : n;
      cx = (m < 1) ? 1 : m;
    }

    Cursor(int n)
    {
      cy = (n < 1) ? 1 : n;
      cx = 1;
    }

    Cursor()
    {
      cy = 1;
      cx = 1;
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

    // Returns the cursor x index.
    unsigned ix();

    // Returns the cursor y index.
    unsigned iy();

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
