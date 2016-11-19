#include <execinfo.h>
#include <fstream>
#include <iostream>
#include <string>
#include <signal.h>
#include <termios.h>
#include <unistd.h>
#include <vector>

#include "cursor.h"
#include "buffer.h"
#include "keypress.h"
#include "options.h"
#include "terminal.h"

void handler(int sig)
{
  void *array[20];
  size_t size;

  size = backtrace(array, 20); // get void*'s for all entries on the stack

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

int main(int argc, char** argv)
{
  signal(SIGSEGV, handler);

  Terminal* terminal = new Terminal();
  terminal->open();

  Cursor* cursor_yx = new Cursor(0, 0);
  Buffer* buffer = new Buffer(*cursor_yx);
  buffer->clear();

  Keypress* keypress = new Keypress(*buffer);

  while(keypress->handle())
  {
    buffer->clear();
    buffer->inspect();
  }

  delete keypress;
  delete buffer;
  delete cursor_yx;

  terminal->close();

  delete terminal;

  return 0;
}
