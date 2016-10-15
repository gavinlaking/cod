#ifndef __BUFFER_H_INCLUDED__
#define __BUFFER_H_INCLUDED__

class Buffer {
  public:
    Buffer(std::string str) {
      content = str;
    }
    Buffer() {
      content = "";
    }

    std::string content;

    void clear() {
      content = "";
    }
};

#endif