#include <iostream>

#include "keypress.h"

int Keypress::handle(void)
{
  this->key = getchar();

  if (this->key == (char)10) // return
  {
    return 0;
  }
  else if (this->key == (char)27) // escape
  {
    return 0;
  }
  else if (this->key == (char)127) // backspace
  {
    return 0;
  }
  else if (this->key > (char)31 && this->key < (char)127)
  {
    return this->key;
  }
  else
  {
    return 0;
  }
}

void Keypress::inspect()
{
  std::cout << (char)this->key << " ";
  std::cout << std::dec << std::uppercase << "Dec: "   << this->key << " ";
  std::cout << std::hex << std::uppercase << "Hex: 0x" << this->key << " ";
  std::cout << std::oct << std::uppercase << "Oct: 0"  << this->key;
  std::cout << std::endl;
}
