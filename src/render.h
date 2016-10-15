#ifndef __RENDER_H_INCLUDED__
#define __RENDER_H_INCLUDED__

class Render {
    string buffer;
  public:
    Render(string str)
    {
      buffer = str;
    }

    void perform()
    {
      cout << ESC_CLEAR_SCREEN;
      cout << ESC_RESET_CURSOR;
      cout << buffer;
    }
};

#endif