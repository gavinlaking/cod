#include <iostream>

#include "keypress.h"

int Keypress::getch(void) {
  // struct termios oldt, newt;

  // tcgetattr(STDIN_FILENO, &oldt);

  // newt = oldt;

  // // and don't echo the keypress.
  // newt.c_lflag &= ~(ICANON | ECHO);

  // tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  this->key = getchar();

  //char *characters = new char[4];

  //std::vector<char> buffer;

  // while(read(STDIN_FILENO, characters, 4) != 0) {
  //   //buffer.push_back(this->key);

  //   if (characters[0] == (char)27) {
  //     if (characters[1] == '[') {
  //       if (characters[2] == 'A') {
  //         std::cout << "[UP]";// << std::endl;
  //       } else if (characters[2] == 'B') {
  //         std::cout << "[DOWN]";// << std::endl;
  //       } else if (characters[2] == 'C') {
  //         std::cout << "[RIGHT]";// << std::endl;
  //       } else if (characters[2] == 'D') {
  //         std::cout << "[LEFT]";// << std::endl;
  //       } else {
  //         std::cout << "\0";
  //       }
  //     } else if (characters[1] == 'O') {
  //       std::cout << "\0";
  //     } else {
  //       std::cout << "\0";
  //     }
  //   } else {
  //     // std::cout << std::dec << std::uppercase << characters[0] \
  //     //           << std::dec << std::uppercase << characters[1] \
  //     //           << std::dec << std::uppercase << characters[2] \
  //     //           << std::dec << std::uppercase << characters[3] \
  //     //           << "!" \
  //     //           << std::dec << std::uppercase << characters[4] \
  //     //           << "!"; // << std::endl;
  //   }

  //   //std::cout << "\e[32m[\e[39m" << (int)characters[0] << "\e[32m]\e[39m";

  //   for(int i = 0; i <= 3; i++) {
  //     std::cout << std::dec << std::uppercase << characters[i];
  //     characters[i] = 0;
      //   }
  // }

  // for(int i = 0; i <= 3; i++) {
  //   std::cout << buffer[i] << std::endl;
  // }

  // tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  // if (this->key == (char)27) {
  //   std::cout << "ESC";

  // } else {
  //   std::cout << "[" << this->key << "]";
  //   return this->key;
  // }

  return this->key;
}

void Keypress::inspect() {
  std::cout << (char)this->key << " ";
  std::cout << std::dec << std::uppercase << "Dec: "   << this->key << " ";
  std::cout << std::hex << std::uppercase << "Hex: 0x" << this->key << " ";
  std::cout << std::oct << std::uppercase << "Oct: 0"  << this->key;
  std::cout << std::endl;
}
