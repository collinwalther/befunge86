#ifndef BEFUNGE_H
#define BEFUNGE_H

#include <vector>
#include <iostream>
#include "Board.h"

class Befunge {
  private:
    Board _board;
    void GetCellsFromLines();

  public:
    void Run();
};

#endif
