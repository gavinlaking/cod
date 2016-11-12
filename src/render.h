#ifndef __RENDER_H_INCLUDED__
#define __RENDER_H_INCLUDED__

class Render
{
    std::string buffer;

  public:
    Render(std::string str)
    {
      buffer = str;
    }

    Render()
    {
      buffer = "";
    }

    // clear the screen and reset the cursor to 1, 1.
    void clear();

    // write the buffer to the screen.
    void write();
};

#endif
