#include <execinfo.h>
#include <fstream>
#include <iostream>
#include <string>
#include <signal.h>
#include <termios.h>
#include <unistd.h>
#include <vector>

#include "terminal.h"
#include "cursor.h"
#include "buffer.h"
#include "keypress.h"
#include "options.h"

void handler(int sig)
{
  void *array[20];
  size_t size;

  size = backtrace(array, 20); // get void*'s for all entries on the stack

  // print out all the frames to stderr
  system("reset"); // reset the terminal
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);

  exit(1);
}

int main(int argc, char** argv)
{
  signal(SIGSEGV, handler);

  Terminal* terminal = new Terminal();
  terminal->open();

  Cursor* cursor = new Cursor(*terminal);
  Buffer* buffer = new Buffer(*cursor);
  buffer->clear();

  Keypress* keypress = new Keypress(*buffer);

  while(keypress->handle())
  {
    buffer->clear();
    buffer->inspect();
  }

  delete keypress;
  delete buffer;
  delete cursor;

  terminal->close();

  delete terminal;

  return 0;
}
