#include "Cell.h"
#include <cassert>

int main() {
    Cell *c = CellFactory::GetCell('a');
    assert(c->GetChar() == 'a');

    c = CellFactory::GetCell('>');
    assert(c->GetChar() == '>');

    return 0;
}
