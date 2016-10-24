#include <iostream>
#include "render.h"

const std::string ESC_CLEAR_SCREEN = "\e[2J";
const std::string ESC_RESET_CURSOR = "\e[1;1H";

void Render::clear() {
  std::cout << ESC_CLEAR_SCREEN;
  std::cout << ESC_RESET_CURSOR;
}

void Render::write() {
  std::cout << this->buffer;
}
