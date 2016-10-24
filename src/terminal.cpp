#include <iostream>
#include "render.h"
#include "terminal.h"

int Terminal::close() { return 0; }

int Terminal::height() { return tyn; }

void Terminal::init() {
  
}

void Terminal::inspect() {
  std::cout << " tx: " << tx << " txn: " << txn;
  std::cout << " ty: " << ty << " tyn: " << tyn;
  std::cout << std::endl;
}

void Terminal::open() {
  Render* render = new Render();
  render->clear();
}

int Terminal::width() { return txn; }
