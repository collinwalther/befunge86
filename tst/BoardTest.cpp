#include "Board.h"
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

int Test3by3Matrix() {
    char row0[] = {'1', '2', '3'};
    char row1[] = {'4', '5', '6'};
    char row2[] = {'7', '8', '9'};
    char *squares[] = {row0, row1, row2};
    Board b(squares, 3, 3);

    vector<Cell *> expectedRow = b.GetRowAt(0);
    assert(expectedRow[0]->GetChar() == '1');
    assert(expectedRow[1]->GetChar() == '2');
    assert(expectedRow[2]->GetChar() == '3');

    return 0;
}

int main() {
    Test3by3Matrix();
   
    return 0;
}
