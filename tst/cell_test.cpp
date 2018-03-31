#include "Cell.h"
#include <cassert>

int main() {
    Cell *c = new Cell('a');
    assert(c->GetChar() == 'a');

    c = new Cell('>');
    assert(c->GetChar() == 'x');

    return 0;
}
