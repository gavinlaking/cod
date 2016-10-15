#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "cursor.h"
#include "keypress.h"
#include "render.h"
#include "terminal.h"

using namespace std;

const string ESC_CLEAR_SCREEN = "\e[2J";
const string ESC_RESET_CURSOR = "\e[1;1H";

class Options
{
  public:
    Options(int argc, char** argv)
    {
      count = argc;
      values = argv;
    };

    int count;
    char** values;

    void inspect()
    {
      cout << "argc: " << count << " argv: [";
      for (int i = 0; i < count; i++)
      {
        if (i == count - 1)
        {
          cout << values[i];
        }
        else
        {
          cout << values[i] << (", ");
        }
      }
      cout << "]";
    }
};

class Buffer
{
  public:
    Buffer(string str)
    {
      content = str;
    }
    Buffer()
    {
      content = "";
    }

    string content;

    void clear()
    {
      content = "";
    }
};

int main(int argc, char** argv)
{
  Render render("Hello world!\n");
  render.perform();

  Options options(argc, argv);
  options.inspect();
  cout << endl;

  Terminal* terminal = new Terminal();
  terminal->inspect();
  cout << endl;

  Cursor* cursor = new Cursor();
  cursor->inspect();
  cout << endl;

  int i = 0;
  while(i < 20)
  {
    Keypress* keypress = new Keypress();
    int key = keypress->getch();
    cout << (char)key;
    i++;
  }

  return 0;
}
