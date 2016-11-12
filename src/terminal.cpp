#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "terminal.h"

void Terminal::close()
{
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int Terminal::height()
{
  return tyn;
}

void Terminal::inspect()
{
  std::cout << " tx: " << tx << " txn: " << txn;
  std::cout << " ty: " << ty << " tyn: " << tyn;
  std::cout << std::endl;
}

void Terminal::open()
{
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

int Terminal::width()
{
  return txn;
}
