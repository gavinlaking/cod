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
#include "render.h"
#include "terminal.h"

int main(int argc, char** argv)
{
  Cursor* cursor_yx = new Cursor(0, 0);
  Buffer* buffer = new Buffer(*cursor_yx);

  Render* render = new Render();
  render->clear();

  Terminal* terminal = new Terminal();
  terminal->open();

  int i = 0;
  while(i < 20)
  {
    Keypress* keypress = new Keypress();
    int key = keypress->handle();
    delete keypress;

    buffer->insert_character(key);

    render->clear();

    buffer->render();

    i++;
  }

  terminal->close();

  delete render;
  delete buffer;
  delete cursor_yx;
  delete terminal;

  return 0;
}
