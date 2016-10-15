#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "keypress.h"

using namespace std;

int Keypress::getch(void)
{
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
	cout << (char)this->key << " ";
  cout << dec << uppercase << "Dec: " << this->key << " ";
 	cout << hex << uppercase << "Hex: 0x" << this->key << " ";
	cout << oct << uppercase << "Oct: 0"  << this->key;
}
