#include <iostream>
#include "cursor.h"

void Cursor::down() {
  cy++;
}

void Cursor::inspect() {
  std::cout << " cx: " << cx;
  std::cout << " cy: " << cy;
  std::cout << std::endl;
}

void Cursor::left() {
  if (cx <= 0) {
    cx = 1;
  } else if (cx - 1 < 1) {
    cx = 1;
  } else {
    cx--;
  }
}

void Cursor::render() {
  std::cout << "\e[" << cy << ";" << cx << "H";
}

void Cursor::right() {
  cx++;
}

void Cursor::up() {
  if (cy <= 0) {
    cy = 1;
  } else if (cy - 1 < 1) {
    cy = 1;
  } else {
    cy--;
  }
}
