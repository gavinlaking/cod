#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "keypress.h"

using namespace std;

int Keypress::getch(void) {
  struct termios oldt, newt;

  tcgetattr(STDIN_FILENO, &oldt);

  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  
  this->key = getchar();
  
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return this->key;
}

void Keypress::inspect() {
	std::cout << (char)this->key << " ";
  std::cout << dec << uppercase << "Dec: "   << this->key << " ";
 	std::cout << hex << uppercase << "Hex: 0x" << this->key << " ";
	std::cout << oct << uppercase << "Oct: 0"  << this->key;
  std::cout << std::endl;
}
