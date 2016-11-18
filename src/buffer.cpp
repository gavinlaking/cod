#include <vector>
#include <fstream>
#include <iostream>

#include "cursor.h"
#include "buffer.h"

const std::string ESC_CLEAR_SCREEN = "\e[2J";
const std::string ESC_RESET_CURSOR = "\e[1;1H";

void Buffer::clear()
{
  std::cout << ESC_CLEAR_SCREEN;
  std::cout << ESC_RESET_CURSOR;
}

void Buffer::inspect()
{
  std::vector< std::vector<char> >::iterator line;
  std::vector<char>::iterator cell;

  if (content.empty())
  {
    std::cout << "Content empty" << std::endl;
  }
  else
  {
    std::cout << "Content exists (lines: ";
    std::cout << line_count() << ")" << std::endl;
    std::cout << "\e[31m[\e[39m" << std::endl;

    for (line = content.begin(); line != content.end(); ++line)
    {
      std::cout << "  \e[32m[\e[39m" << std::endl;

      for (cell = line->begin(); cell != line->end(); ++cell)
      {
        std::cout << "    \e[33m[\e[39m" << *cell << "\e[33m]\e[39m" << std::endl;
      }

      std::cout << "  \e[32m]\e[39m" << std::endl;
    }
    std::cout << "\e[31m]\e[39m" << std::endl;
  }
}

void Buffer::insert_line(std::string str)
{
  std::vector<char> line(str.begin(), str.end());
  content.push_back(line);
}

void Buffer::insert_character(char c)
{
  unsigned yi = m_cursor.cy;
  unsigned xi = m_cursor.cx;

  std::vector<char> line = find_line();
  line.insert(line.begin() + xi, c);
  content.insert(content.begin() + yi, line);
  remove_line(yi + 1);

  m_cursor.right();
}

void Buffer::read_file(std::string filename)
{
  std::ifstream infile;
  std::string line;

  infile.open(filename);

  if (infile.is_open())
  {
    while(std::getline(infile, line))
    {
      insert_line(line);
    }
  }
  else
  {
    std::cout << "File not found." << std::endl;
  }

  infile.close();
}

void Buffer::remove_line(unsigned yi)
{
  if (content.size() > yi)
  {
    content.erase(content.begin() + yi);
  }
}

void Buffer::remove_character()
{
  unsigned yi = m_cursor.cy;
  unsigned xi = m_cursor.cx;

  std::vector<char> line = find_line();
  line.erase(line.begin() + xi - 1);

  content.insert(content.begin() + yi, line);

  remove_line(yi + 1);

  m_cursor.left();
}

void Buffer::render()
{
  std::vector< std::vector<char> >::iterator line;
  std::vector<char>::iterator cell;

  if (content.empty())
  {
    std::cout << "";
  }
  else
  {
    for (line = content.begin(); line != content.end(); ++line)
    {
      for (cell = line->begin(); cell != line->end(); ++cell)
      {
        std::cout << *cell;
      }
    }
  }
}

int Buffer::character_count()
{
  return find_line().size();
}

std::vector<char> Buffer::find_line()
{
  unsigned yi = m_cursor.cy;
  return content.at(yi);
}

int Buffer::line_count()
{
  return content.size();
}
