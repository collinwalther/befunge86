#ifndef BEFUNGE_H
#define BEFUNGE_H

#include <vector>
#include <iostream>
#include "Board.h"
#include "Label.h"

class Befunge {
  private:
    std::istream *_is;
    std::ostream *_os;
    Board _board;
    void ReadInputStream();
    void SetCellAdjacencies();
    void OutputEntryPoint();
    void OutputLeftToRight();
    void OutputRightToLeft();
    void OutputUpToDown();
    void OutputDownToUp();
    void OutputConstants();

  public:
    static Label charPrintSpecifierLabel, 
                 intPrintSpecifierLabel,
                 charScanSpecifierLabel,
                 intScanSpecifierLabel,
                 stringModeLabel;
    Befunge(std::istream *is, std::ostream *os);
    void Run();
};

#endif
