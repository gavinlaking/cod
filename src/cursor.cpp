#include <iostream>
#include "cursor.h"

int Cursor::down()
{
  return cy++;
}

void Cursor::inspect()
{
  std::cout << " cx: " << std::to_string(cx);
  std::cout << " cy: " << std::to_string(cy);
  std::cout << " tcx: " << std::to_string(tmp_cx);
  std::cout << " tcy: " << std::to_string(tmp_cy);
}

int Cursor::left()
{
  if (cx - 1 < 0)
  {
    return cx = 0;
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
  std::cout << "\e[" << std::to_string(cy) << ";" << std::to_string(cx) << "f";
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
  if (cy - 1 < 0)
  {
    return cy = 0;
  }
  else
  {
    return cy--;
  }
}
