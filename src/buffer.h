#ifndef __BUFFER_H_INCLUDED__
#define __BUFFER_H_INCLUDED__

class Buffer
{
  private:
    int character_count(unsigned yi);
    std::vector<char> find_line(unsigned yi);
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
    void insert_character(char c);
    void read_file(std::string filename);
    void remove_line(unsigned yi);
    void remove_character();
    void render();
};

#endif
