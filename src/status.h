#ifndef __STATUS_H_INCLUDED__
#define __STATUS_H_INCLUDED__

class Status {
  int sx;
  int sy;
  int sxn;
  int syn;

  public:
    Status() {
      sx = 1;
      sy = 24;
      sxn = 90;
      syn = 24;
    }

    void update();
};

#endif