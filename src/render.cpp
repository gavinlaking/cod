#include <iostream>
#include "render.h"

const std::string ESC_CLEAR_SCREEN = "\e[2J";
const std::string ESC_RESET_CURSOR = "\e[1;1H";

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

void Render::clear() {
  std::cout << ESC_CLEAR_SCREEN;
  std::cout << ESC_RESET_CURSOR;

  // std::cout << ESC_BG_BLACK   << "Black"   << ESC_BG_DEFAULT;
  // std::cout << ESC_BG_RED     << "Red"     << ESC_BG_DEFAULT;
  // std::cout << ESC_BG_GREEN   << "Green"   << ESC_BG_DEFAULT;
  // std::cout << ESC_BG_YELLOW  << "Yellow"  << ESC_BG_DEFAULT;
  // std::cout << ESC_BG_BLUE    << "Blue"    << ESC_BG_DEFAULT;
  // std::cout << ESC_BG_MAGENTA << "Magenta" << ESC_BG_DEFAULT;
  // std::cout << ESC_BG_CYAN    << "Cyan"    << ESC_BG_DEFAULT;
  // std::cout << ESC_BG_WHITE   << "White"   << ESC_BG_DEFAULT;
  // std::cout << ESC_BG_DEFAULT << "Default" << ESC_BG_DEFAULT;

  // std::cout << ESC_FG_BLACK   << "Black"   << ESC_FG_DEFAULT;
  // std::cout << ESC_FG_RED     << "Red"     << ESC_FG_DEFAULT;
  // std::cout << ESC_FG_GREEN   << "Green"   << ESC_FG_DEFAULT;
  // std::cout << ESC_FG_YELLOW  << "Yellow"  << ESC_FG_DEFAULT;
  // std::cout << ESC_FG_BLUE    << "Blue"    << ESC_FG_DEFAULT;
  // std::cout << ESC_FG_MAGENTA << "Magenta" << ESC_FG_DEFAULT;
  // std::cout << ESC_FG_CYAN    << "Cyan"    << ESC_FG_DEFAULT;
  // std::cout << ESC_FG_WHITE   << "White"   << ESC_FG_DEFAULT;
  // std::cout << ESC_FG_DEFAULT << "Default" << ESC_FG_DEFAULT;
}

void Render::write() {
  std::cout << this->buffer;
}
