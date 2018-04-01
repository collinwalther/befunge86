#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <vector>

class Board {
  private:
    int _width;
    int _height;
    std::vector<std::vector<Cell *> *> _cells;
    
  public:
    Board();
    Board(char** b, int width, int height);
    int GetWidth() { return _width; }
    int GetHeight() { return _height; }
    std::vector<std::vector<Cell *> *> GetCells() { return _cells; }
    std::vector<Cell *> GetRowAt(int rowIndex);
    std::vector<Cell *> GetColumnAt(int columnIndex);
    void SetRowAt(std::vector<Cell *> row, int rowIndex);
};

#endif
