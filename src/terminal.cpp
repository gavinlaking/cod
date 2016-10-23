#include <iostream>
#include "terminal.h"

int Terminal::height() { return tyn; }

void Terminal::inspect() {
  std::cout << " tx: " << tx << " txn: " << txn;
  std::cout << " ty: " << ty << " tyn: " << tyn;
  std::cout << std::endl;
}

int Terminal::width() { return txn; }
