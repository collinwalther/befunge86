#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <vector>

class Board {
  private:
    unsigned _width;
    unsigned _height;
    std::vector<std::vector<Cell *> *> _cells;
    
  public:
    Board();
    Board(char** b, unsigned width, unsigned height);
    unsigned GetWidth() { return _width; }
    unsigned GetHeight() { return _height; }
    std::vector<std::vector<Cell *> *> GetCells() { return _cells; }
    std::vector<Cell *> GetRowAt(unsigned rowIndex);
    std::vector<Cell *> GetColumnAt(unsigned columnIndex);
    void SetRowAt(std::vector<Cell *> row, unsigned rowIndex);
};

#endif
