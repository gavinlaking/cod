#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "status.h"

void Status::update() {

  // TODO: store cursor position

  std::cout << "\e[43m";
  std::cout << "\e[" << sy << ";" << sx << "H";
  for(int x = 1;x < (sxn - 1);x++)
  {
    std::cout << " ";
  }
  std::cout << "\e[30m";
  std::cout << "\e[" << sy << ";" << sxn << "H";
  std::cout << " X" << sxn << ", 999 ";
  std::cout << "\e[39m";
  std::cout << "\e[49m";

  // TODO: restore cursor position
  std::cout << "\e[1;1H";
}
