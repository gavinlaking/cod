#include <iostream>
#include <istream>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <vector>

#include "terminal.h"
#include "cursor.h"
#include "buffer.h"
#include "keypress.h"

bool Keypress::handle(void)
{
  //key = getchar();

  int length = 4;
  char keypress[length];
  std::cin.get(keypress, length, '\0');

  if (strcmp(keypress, "\033[A") == 0) // up
  {

  }
  if (strcmp(keypress, "\033[B") == 0) // down
  {

  }
  if (strcmp(keypress, "\033[C") == 0) // right
  {

  }
  if (strcmp(keypress, "\033[D") == 0) // left
  {

  }
  if (strcmp(keypress, "\177") == 0) // backspace
  {

  }
  if (strcmp(keypress, '\n') == 0) // enter
  {
    m_buffer.insert_line("");
  }


  if (keypress == "\n") // return
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
