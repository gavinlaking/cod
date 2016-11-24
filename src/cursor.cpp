#include <iostream>
#include <sys/ioctl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "terminal.h"
#include "cursor.h"

int Cursor::bottom()
{
  return cy = m_terminal.tyn;
}

int Cursor::leftmost()
{
  return cx = m_terminal.tx;
}

int Cursor::rightmost()
{
  return cx = m_terminal.txn;
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
}

unsigned Cursor::ix()
{
  if (cx - 1 < 1)
  {
    return 0;
  }
  else
  {
    return cx - 1;
  }
}

unsigned Cursor::iy()
{
  if (cy - 1 < 1)
  {
    return 0;
  }
  else
  {
    return cy - 1;
  }
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

void Cursor::position(int n, int m)
{
  store();
  cy = (n < 1) ? 1 : n;
  cx = (m < 1) ? 1 : m;

  render();
}

void Cursor::reset()
{
  cy = 1;
  cx = 1;

  render();
}

void Cursor::restore()
{
  std::cout << "\e[u";
}

void Cursor::render()
{
  std::cout << "\e[";
  std::cout << std::to_string(cy);
  std::cout << ";";
  std::cout << std::to_string(cx);
  std::cout << "f"; // can be either 'f' or 'H'
}

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
  return cy = m_terminal.tx;
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
