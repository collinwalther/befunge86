#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell {
  private:
    char _c;

  public:
    Cell(char c);
    char GetChar() const;
};

std::ostream& operator<<(std::ostream& os, const Cell& c);

#endif
