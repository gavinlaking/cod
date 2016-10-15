#include <iostream>
#include "cursor.h"

using namespace std;

void Cursor::down()
{
  cy++;
}

void Cursor::inspect()
{
  cout << " cx: " << cx << " cy: " << cy;
}

void Cursor::left()
{
  if (cx <= 0)
  {
    cx = 1;
  }
  else if (cx - 1 < 1)
  {
    cx = 1;
  }
  else
  {
    cx--;
  }
}

void Cursor::render()
{
  cout << "\e[" << cy << ";" << cx << "H";
}

void Cursor::right()
{
  cx++;
}

void Cursor::up()
{
  if (cy <= 0)
  {
    cy = 1;
  }
  else if (cy - 1 < 1)
  {
    cy = 1;
  }
  else
  {
    cy--;
  }
}
