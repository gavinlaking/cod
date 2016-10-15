#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "cursor.h"
#include "terminal.h"

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
