#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "keypress.h"

int Keypress::getch(void) {
  struct termios oldt, newt;

  tcgetattr(STDIN_FILENO, &oldt);

  newt = oldt;

  // and don't echo the keypress.
  newt.c_lflag &= ~(ICANON | ECHO);

  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  this->key = getchar();
  if (this->key == (char)27) {}

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return this->key;
}

void Keypress::inspect() {
  std::cout << (char)this->key << " ";
  std::cout << std::dec << std::uppercase << "Dec: "   << this->key << " ";
  std::cout << std::hex << std::uppercase << "Hex: 0x" << this->key << " ";
  std::cout << std::oct << std::uppercase << "Oct: 0"  << this->key;
  std::cout << std::endl;
}
