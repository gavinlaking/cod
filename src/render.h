#ifndef __RENDER_H_INCLUDED__
#define __RENDER_H_INCLUDED__

class Render {
    std::string buffer;
  public:
    Render(std::string str) {
      buffer = str;
    }

    void perform();
};

#endif