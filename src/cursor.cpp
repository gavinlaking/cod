#include <iostream>
#include "cursor.h"

int Cursor::down()
{
  return cy++;
}

void Cursor::inspect()
{
  std::cout << " cx: " << cx;
  std::cout << " cy: " << cy;
  std::cout << std::endl;
}

int Cursor::left()
{
  if (cx - 1 < 1)
  {
    return cx = 1;
  }
  else
  {
    return cx--;
  }
}

void Cursor::restore()
{
  cx = tmp_cx;
  cy = tmp_cy;
}

void Cursor::render()
{
  std::cout << "\e[" << cy << ";" << cx << "H";
}

int Cursor::right()
{
  return cx++;
}

void Cursor::store()
{
  tmp_cx = cx;
  tmp_cy = cy;
}

int Cursor::up()
{
  if (cy - 1 < 1)
  {
    return cy = 1;
  }
  else
  {
    return cy--;
  }
}
