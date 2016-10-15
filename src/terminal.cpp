#include <iostream>
#include "terminal.h"

using namespace std;

void Terminal::inspect()
{
  cout << " tx: " << tx << " txn: " << txn;
  cout << " ty: " << ty << " tyn: " << tyn;
}
