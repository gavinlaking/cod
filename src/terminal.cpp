#include <iostream>
#include "terminal.h"

void Terminal::inspect() {
  std::cout << " tx: " << tx << " txn: " << txn;
  std::cout << " ty: " << ty << " tyn: " << tyn;
  std::cout << std::endl;
}
