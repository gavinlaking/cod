#include <vector>
#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "buffer.h"
#include "cursor.h"
#include "keypress.h"
#include "options.h"
#include "render.h"
#include "terminal.h"

int main(int argc, char** argv) {
  Terminal* terminal = new Terminal();
  terminal->open();

  Keypress* keypress = new Keypress();

  int i = 0;
  while(i < 20) {
    int key = keypress->getch();
    std::cout << (char)key;
    i++;
  }

  terminal->close();
}
