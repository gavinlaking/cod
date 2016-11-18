#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "terminal.h"

const std::string ESC_BG_BLACK = "\e[40m";
const std::string ESC_BG_RED = "\e[41m";
const std::string ESC_BG_GREEN = "\e[42m";
const std::string ESC_BG_YELLOW = "\e[43m";
const std::string ESC_BG_BLUE = "\e[44m";
const std::string ESC_BG_MAGENTA = "\e[45m";
const std::string ESC_BG_CYAN = "\e[46m";
const std::string ESC_BG_WHITE = "\e[47m";
const std::string ESC_BG_DEFAULT = "\e[49m";

const std::string ESC_FG_BLACK = "\e[30m";
const std::string ESC_FG_RED = "\e[31m";
const std::string ESC_FG_GREEN = "\e[32m";
const std::string ESC_FG_YELLOW = "\e[33m";
const std::string ESC_FG_BLUE = "\e[34m";
const std::string ESC_FG_MAGENTA = "\e[35m";
const std::string ESC_FG_CYAN = "\e[36m";
const std::string ESC_FG_WHITE = "\e[37m";
const std::string ESC_FG_DEFAULT = "\e[39m";

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
