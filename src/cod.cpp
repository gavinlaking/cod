#include <fstream>
#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <vector>

#include "buffer.h"
#include "cursor.h"
#include "keypress.h"
#include "options.h"
#include "render.h"
#include "terminal.h"

int main(int argc, char** argv) {
  Terminal* terminal = new Terminal();
  terminal->open();

  Cursor* cursor_yx = new Cursor(0, 0);
  cursor_yx->inspect();
  //delete cursor_yx;

  Buffer* buffer = new Buffer();
  // buffer->read_file("test.txt");
  // buffer->remove_line(0); // remove initialized empty line
  // buffer->insert_line("hello");
  // buffer->insert_line("the");
  // buffer->insert_line("world");
  // buffer->remove_line(1);
  // buffer->remove_character(1, 2);
  // buffer->insert_character(0, 0, 'c');
  // buffer->insert_character(1, 4, 's');
  // 
  
  Keypress* keypress = new Keypress();

  int i = 0;
  while(i < 20) {
    int key = keypress->getch();

    buffer->insert_character(cursor_yx->cy - 1, cursor_yx->cx - 1, key);
    buffer->inspect();
    i++;
  }

  terminal->close();
  
  delete keypress;
  delete buffer;
  delete cursor_yx;
  delete terminal;
}
