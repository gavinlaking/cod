#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

const string ESC_CLEAR_SCREEN = "\e[2J";
const string ESC_RESET_CURSOR = "\e[1;1H";

class Buffer {
  public:
    Buffer(string str) { content = str; }

    string content;

    void clear() {
      content = "";
    }
};

class Cursor {
  public:
    Cursor(int n, int m) {
      cy = n;
      cx = m;
    }
    Cursor(int n) {
      cy = n;
      cx = 1;
    }
    Cursor() {
      cy = 1;
      cx = 1;
    }

    int cy;
    int cx;

    void down() {
      cy++;
    }
    void inspect() {
      cout << " cx: " << cx << " cy: " << cy << endl;
    }
    void left() {
      if (cx <= 0) {
        cx = 1;
      } else if (cx - 1 < 1) {
        cx = 1;
      } else {
        cx--;
      }
    }
    void render() {
      cout << "\e[" << cy << ";" << cx << "H";
    }
    void right() {
      cx++;
    }
    void up() {
      if (cy <= 0) {
        cy = 1;
      } else if (cy - 1 < 1) {
        cy = 1;
      } else {
        cy--;
      }
    }
};

class Render {
    string buffer;
  public:
    Render(string str) { buffer = str; }

    void perform() {
      cout << ESC_CLEAR_SCREEN;
      cout << ESC_RESET_CURSOR;
      cout << buffer;
    }
};

class Terminal {
  public:
    Terminal() {
      tx = 1;
      ty = 1;
      txn = 80;
      tyn = 25;
    }

    int tx;
    int ty;
    int txn;
    int tyn;

    void inspect() {
      cout << " tx: " << tx << " txn: " << txn;
      cout << " ty: " << ty << " tyn: " << tyn;
    }
};

int main(int argc, char** argv) {
  Render render("Hello world!\n");
  render.perform();

  cout << "Have " << argc << " arguments:" << endl;
  for (int i = 0; i < argc; ++i) {
    cout << argv[i] << endl;
  }

  Terminal* terminal = new Terminal();
  terminal->inspect();
  cout << endl;

  Cursor* cursor = new Cursor();
  cursor->inspect();
  cout << endl;

  int i = 0;
  while(i < 20) {
    cout << i << endl;
    i++;
    sleep(0.5);
  }

  return 0;
}
