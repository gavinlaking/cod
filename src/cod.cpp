#include <iostream>

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
};

int main() {
  Render render("Hello world!\n");
  render.perform();

  int i = 0;
  while(i < 20) {
    cout << i << endl;
    i++;
  }

  return 0;
}
