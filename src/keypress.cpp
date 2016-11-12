#include <iostream>

#include "keypress.h"

int Keypress::getch(void) {
  this->key = getchar();

  if (this->key > (char)31 && this->key < (char)127) {
    return this->key;
  } else {
    return 0;
  }
}

void Keypress::inspect() {
  std::cout << (char)this->key << " ";
  std::cout << std::dec << std::uppercase << "Dec: "   << this->key << " ";
  std::cout << std::hex << std::uppercase << "Hex: 0x" << this->key << " ";
  std::cout << std::oct << std::uppercase << "Oct: 0"  << this->key;
  std::cout << std::endl;
}
