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

int main() {
  Render render("Hello world!\n");
  render.perform();
  return 0;
}
