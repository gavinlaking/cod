#ifndef __OPTIONS_H_INCLUDED__
#define __OPTIONS_H_INCLUDED__

class Options {
  public:
    Options(int argc, char** argv) {
      count = argc;
      values = argv;
    }

    int count;
    char** values;

    void inspect();
};

#endif
