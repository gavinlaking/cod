#include <vector>
#include <iostream>

#include "cursor.h"
#include "buffer.h"
#include "keypress.h"

void Keypress::handle(void)
{
  key = getchar();

  if (key == (char)10) // return
  {
  }
  else if (key == (char)27) // escape
  {
  }
  else if (key == (char)127) // backspace
  {
    m_buffer.remove_character();
  }
  else if (key > (char)31 && key < (char)127)
  {
    m_buffer.insert_character(key);
  }
  else
  {
  }
}

void Keypress::inspect()
{
  std::cout << (char)key << " ";
  std::cout << std::dec << std::uppercase << "Dec: "   << key << " ";
  std::cout << std::hex << std::uppercase << "Hex: 0x" << key << " ";
  std::cout << std::oct << std::uppercase << "Oct: 0"  << key;
  std::cout << std::endl;
}
