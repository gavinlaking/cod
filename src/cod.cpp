#include <fstream>
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <vector>

#include "cursor.h"
#include "buffer.h"
#include "keypress.h"
#include "options.h"
#include "terminal.h"

int main(int argc, char** argv)
{
  Terminal* terminal = new Terminal();
  terminal->open();

  Cursor* cursor_yx = new Cursor(0, 0);
  Buffer* buffer = new Buffer(*cursor_yx);
  buffer->clear();

  Keypress* keypress = new Keypress(*buffer);

  while(keypress->handle())
  {
    buffer->clear();
    buffer->render();
  }

  delete keypress;
  delete buffer;
  delete cursor_yx;

  terminal->close();

  delete terminal;

  return 0;
}
