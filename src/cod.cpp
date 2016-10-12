#include <iostream>

using namespace std;

const string ESC_CLEAR_SCREEN = "\e[2J";
const string ESC_RESET_CURSOR = "\e[1;1H";

class Render {
    string buffer;
  public:
    Render(string);

    int perform() {
      cout << ESC_CLEAR_SCREEN;
      cout << ESC_RESET_CURSOR;
      cout << buffer;
      return 0;
    }
};

Render::Render(string str) {
  buffer = str;
}

int main() {
  Render render("Hello world!\n");
  render.perform();
  return 0;
}

