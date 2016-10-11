#include <iostream>

using namespace std;

const string ESC_CLEAR_SCREEN = "\e[2J";
const string ESC_RESET_CURSOR = "\e[1;1H";

int main() {
  cout << ESC_CLEAR_SCREEN + ESC_RESET_CURSOR + "Hello world!\n";
  return 0;
}

