#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "buffer.h"
#include "cursor.h"
#include "keypress.h"
#include "render.h"
#include "terminal.h"

class Options {
  public:
    Options(int argc, char** argv) {
      count = argc;
      values = argv;
    }

    int count;
    char** values;

    void inspect() {
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
};

int main(int argc, char** argv) {
  Render* render = new Render("Hello world!\n");
  render->perform();

  Options* options = new Options(argc, argv);
  options->inspect();

  Terminal* terminal = new Terminal();
  terminal->inspect();

  Cursor* cursor = new Cursor();
  cursor->inspect();

  int i = 0;
  while(i < 20) {
    Keypress* keypress = new Keypress();
    int key = keypress->getch();
    std::cout << (char)key;
    i++;
  }

  return 0;
}
