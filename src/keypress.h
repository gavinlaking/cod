#ifndef __KEYPRESS_H_INCLUDED__
#define __KEYPRESS_H_INCLUDED__

class Keypress
{
  private:
    int key;
    Buffer& m_buffer;

  public:
    Keypress(Buffer& buffer) : m_buffer(buffer) {}

    void handle();
    void inspect();
};

#endif
