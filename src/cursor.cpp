#include <iostream>
#include "cursor.h"

 // TODO: get height from Terminal
int Cursor::bottom()
{
  return cy = 25;
}

int Cursor::leftmost()
{
  return cx = 0;
}

// TODO: get width from Terminal
int Cursor::rightmost()
{
  return cx = 80;
}

// TODO: get bottom from Terminal
int Cursor::down()
{
  return cy++;
}

void Cursor::inspect()
{
  std::cout << "\e[s"; // store cursor
  std::cout << "\e[25;80H"; // position cursor
  std::cout << " cx: " << std::to_string(cx);
  std::cout << " cy: " << std::to_string(cy);

  std::cout << "\e[u"; // restore cursor
  // std::cout << " tcx: " << std::to_string(tmp_cx);
  // std::cout << " tcy: " << std::to_string(tmp_cy);
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

void Cursor::position(int n, int m)
{
  store();
  cy = (n < 0) ? 0 : n;
  cx = (m < 0) ? 0 : m;
  render();
}

void Cursor::restore()
{
  std::cout << "\e[u";
}

// can be either 'f' or 'H'
void Cursor::render()
{
  std::cout << "\e[" << std::to_string(cy + 1) << ";" << std::to_string(cx + 1) << "f";
}

// TODO: get width from Terminal
int Cursor::right()
{
  return cx++;
}

void Cursor::store()
{
  std::cout << "\e[s";
}

int Cursor::top()
{
  return cy = 0;
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
