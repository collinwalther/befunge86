#include "Cell.h"
#include <iostream>

Cell::Cell(char c) {
    _c = c;
}

char Cell::GetChar() const {
    return _c;
}

std::ostream& operator<<(std::ostream& os, const Cell& c) {
   //TODO
   std::cout << c.GetChar() << std::endl;
   return os;
}
