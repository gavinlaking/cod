#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "buffer.h"
#include "cursor.h"
#include "keypress.h"
#include "options.h"
#include "render.h"
#include "status.h"
#include "terminal.h"

int main(int argc, char** argv) {
  Render* render = new Render("Hello world!\n");
  render->perform();

  Options* options = new Options(argc, argv);
  options->inspect();

  Terminal* terminal = new Terminal();
  terminal->inspect();

  Cursor* cursor = new Cursor();
  cursor->inspect();

  Status* status = new Status();

  int i = 0;
  while(i < 20) {
    Keypress* keypress = new Keypress();
    int key = keypress->getch();

    keypress->inspect();

    std::cout << (char)key << std::endl;
    
    status->update();

    i++;
  }

  return 0;
}
