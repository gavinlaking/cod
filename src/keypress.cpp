#include <vector>
#include <iostream>

#include "cursor.h"
#include "buffer.h"
#include "keypress.h"

bool Keypress::handle(void)
{
  key = getchar();

  if (key == (char)10) // return
  {
    m_buffer.insert_line("");
  }
  else if (key == (char)27) // escape
  {
    return false;
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
  return true;
}

void Keypress::inspect()
{
  std::cout << (char)key << " ";
  std::cout << std::dec << std::uppercase << "Dec: "   << key << " ";
  std::cout << std::hex << std::uppercase << "Hex: 0x" << key << " ";
  std::cout << std::oct << std::uppercase << "Oct: 0"  << key;
  std::cout << std::endl;
}
