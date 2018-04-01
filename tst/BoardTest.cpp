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

    vector<Cell *> e = b.GetRowAt(0);
    assert(e[0]->GetChar() == '1');
    assert(e[1]->GetChar() == '2');
    assert(e[2]->GetChar() == '3');
    assert(e.size() == 3);

    e = b.GetRowAt(1);
    assert(e[0]->GetChar() == '4');
    assert(e[1]->GetChar() == '5');
    assert(e[2]->GetChar() == '6');
    assert(e.size() == 3);

    e = b.GetRowAt(2);
    assert(e[0]->GetChar() == '7');
    assert(e[1]->GetChar() == '8');
    assert(e[2]->GetChar() == '9');
    assert(e.size() == 3);

    e = b.GetColumnAt(0);
    assert(e[0]->GetChar() == '1');
    assert(e[1]->GetChar() == '4');
    assert(e[2]->GetChar() == '7');
    assert(e.size() == 3);

    e = b.GetColumnAt(1);
    assert(e[0]->GetChar() == '2');
    assert(e[1]->GetChar() == '5');
    assert(e[2]->GetChar() == '8');
    assert(e.size() == 3);

    e = b.GetColumnAt(2);
    assert(e[0]->GetChar() == '3');
    assert(e[1]->GetChar() == '6');
    assert(e[2]->GetChar() == '9');
    assert(e.size() == 3);

    return 0;
}

int Test3by3MatrixWithHole() {
    char row0[] = {'1', '2', '3'};
    char row1[] = {'4', ' ', '6'};
    char row2[] = {'7', '8', '9'};
    char *squares[] = {row0, row1, row2};
    Board b(squares, 3, 3);

    vector<Cell *> e = b.GetRowAt(0);
    assert(e[0]->GetChar() == '1');
    assert(e[1]->GetChar() == '2');
    assert(e[2]->GetChar() == '3');
    assert(e.size() == 3);

    e = b.GetRowAt(1);
    assert(e[0]->GetChar() == '4');
    assert(e[1]->GetChar() == ' ');
    assert(e[2]->GetChar() == '6');
    assert(e.size() == 3);

    e = b.GetRowAt(2);
    assert(e[0]->GetChar() == '7');
    assert(e[1]->GetChar() == '8');
    assert(e[2]->GetChar() == '9');
    assert(e.size() == 3);

    e = b.GetColumnAt(0);
    assert(e[0]->GetChar() == '1');
    assert(e[1]->GetChar() == '4');
    assert(e[2]->GetChar() == '7');
    assert(e.size() == 3);

    e = b.GetColumnAt(1);
    assert(e[0]->GetChar() == '2');
    assert(e[1]->GetChar() == ' ');
    assert(e[2]->GetChar() == '8');
    assert(e.size() == 3);

    e = b.GetColumnAt(2);
    assert(e[0]->GetChar() == '3');
    assert(e[1]->GetChar() == '6');
    assert(e[2]->GetChar() == '9');
    assert(e.size() == 3);

    return 0;
}

int TestStaircase() {
    Board b;
    vector<Cell *> row0, row1, row2;
    row0.push_back(new Cell('1'));
    row1.push_back(new Cell('4'));    row1.push_back(new Cell('5'));
    row2.push_back(new Cell('7'));    row2.push_back(new Cell('8'));    row2.push_back(new Cell('9'));
    b.SetRowAt(row0, 0);
    b.SetRowAt(row1, 1);
    b.SetRowAt(row2, 2);

    vector<Cell *> e = b.GetRowAt(0);
    assert(e[0]->GetChar() == '1');
    assert(e.size() == 3);

    e = b.GetRowAt(1);
    assert(e[0]->GetChar() == '4');
    assert(e[1]->GetChar() == '5');
    assert(e.size() == 3);

    e = b.GetRowAt(2);
    assert(e[0]->GetChar() == '7');
    assert(e[1]->GetChar() == '8');
    assert(e[2]->GetChar() == '9');
    assert(e.size() == 3);

    e = b.GetColumnAt(0);
    assert(e[0]->GetChar() == '1');
    assert(e[1]->GetChar() == '4');
    assert(e[2]->GetChar() == '7');
    assert(e.size() == 3);

    e = b.GetColumnAt(1);
    assert(e[0]->GetChar() == ' ');
    assert(e[1]->GetChar() == '5');
    assert(e[2]->GetChar() == '8');
    assert(e.size() == 3);

    e = b.GetColumnAt(2);
    assert(e[0]->GetChar() == ' ');
    assert(e[1]->GetChar() == ' ');
    assert(e[2]->GetChar() == '9');
    assert(e.size() == 3);

    return 0;
}

int TestInverseStaircase() {
    Board b;
    vector<Cell *> row0, row1, row2;
    row0.push_back(new Cell('1'));  row0.push_back(new Cell('2'));  row0.push_back(new Cell('3'));
    row1.push_back(new Cell('4'));  row1.push_back(new Cell('5'));
    row2.push_back(new Cell('7'));
    b.SetRowAt(row0, 0);
    b.SetRowAt(row1, 1);
    b.SetRowAt(row2, 2);

    vector<Cell *> e = b.GetRowAt(0);
    assert(e[0]->GetChar() == '1');
    assert(e[1]->GetChar() == '2');
    assert(e[2]->GetChar() == '3');
    assert(e.size() == 3);

    e = b.GetRowAt(1);
    assert(e[0]->GetChar() == '4');
    assert(e[1]->GetChar() == '5');
    assert(e[2]->GetChar() == ' ');
    assert(e.size() == 3);

    e = b.GetRowAt(2);
    assert(e[0]->GetChar() == '7');
    assert(e[1]->GetChar() == ' ');
    assert(e[2]->GetChar() == ' ');
    assert(e.size() == 3);

    e = b.GetColumnAt(0);
    assert(e[0]->GetChar() == '1');
    assert(e[1]->GetChar() == '4');
    assert(e[2]->GetChar() == '7');
    assert(e.size() == 3);

    e = b.GetColumnAt(1);
    assert(e[0]->GetChar() == '2');
    assert(e[1]->GetChar() == '5');
    assert(e[2]->GetChar() == ' ');
    assert(e.size() == 3);

    e = b.GetColumnAt(2);
    assert(e[0]->GetChar() == '3');
    assert(e[1]->GetChar() == ' ');
    assert(e[2]->GetChar() == ' ');
    assert(e.size() == 3);

    return 0;
}

int main() {
    Test3by3Matrix();
    Test3by3MatrixWithHole();
    TestStaircase();
    TestInverseStaircase();
   
    return 0;
}
