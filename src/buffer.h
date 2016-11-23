#ifndef __BUFFER_H_INCLUDED__
#define __BUFFER_H_INCLUDED__

class Buffer
{
  private:
    int character_count();
    std::vector<char> find_line();
    int line_count();
    Cursor& m_cursor;

  public:
    Buffer(Cursor& cursor) : m_cursor(cursor)
    {
      content = { {} };
    }

    std::vector< std::vector<char> > content;

    void clear();
    void inspect();
    void insert_line(std::string str);
    void insert_character(char character);
    void move_cursor_down();
    void move_cursor_left();
    void move_cursor_leftmost();
    void move_cursor_right();
    void move_cursor_rightmost();
    void move_cursor_up();
    void read_file(std::string filename);
    void remove_line(unsigned iy);
    void remove_character();
    void render();
};

#endif
