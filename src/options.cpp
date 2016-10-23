#include <iostream>
#include "options.h"

void Options::inspect() {
  std::cout << "argc: " << count << " argv: [";
  for (int i = 0; i < count; i++)
  {
    if (i == count - 1)
    {
      std::cout << values[i];
    }
    else
    {
      std::cout << values[i] << (", ");
    }
  }
  std::cout << "]";
}