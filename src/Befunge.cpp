#include "Befunge.h"
#include "Label.h"
#include <vector>
#include <iostream>

Befunge::Befunge(std::istream *is, std::ostream *os) {
    _is = is;
    _os = os;
}

Label Befunge::charPrintSpecifierLabel = Label();
Label Befunge::intPrintSpecifierLabel = Label();
Label Befunge::charScanSpecifierLabel = Label();
Label Befunge::intScanSpecifierLabel = Label();
Label Befunge::stringModeLabel = Label();

void Befunge::Run() {
    ReadInputStream();
    OutputConstants();
    OutputEntryPoint();
    OutputLeftToRight();
    OutputRightToLeft();
    OutputUpToDown();
    OutputDownToUp();
}

void Befunge::ReadInputStream() {
    // Read stdin until EOF
    int lineNumber = 0;
    while (true) {
        // Read the line:
        std::string line;
        getline(*_is, line);

        // For every character in the line, create a
        // cell from it and push it onto our cells.
        std::vector<Cell *> row;
        for (unsigned i = 0; i < line.size(); i++) {
            row.push_back(CellFactory::GetCell(line[i]));
        }
        _board.SetRowAt(row, lineNumber);
        lineNumber++;

        // If EOF was encountered while getting this line,
        // then stop reading lines.
        if (_is->eof()) {
            break;
        }
    }
}

void Befunge::OutputEntryPoint() {
    *_os << ".text\n"
         << "\t.globl\tmain\n"
         << "main:\n";
}

void Befunge::OutputLeftToRight() {
    for (unsigned i = 0; i < _board.GetHeight(); i++) {
        std::vector<Cell *> row = _board.GetRowAt(i);
        for (unsigned j = 0; j < row.size(); j++) {
            *_os << row[j]->GetOp(RIGHT);
        }
        *_os << std::endl;
    }
}

void Befunge::OutputRightToLeft() {
    for (unsigned i = 0; i < _board.GetHeight(); i++) {
        std::vector<Cell *> row = _board.GetRowAt(i);
        for (unsigned j = row.size(); j > 0; j--) {
            *_os << row[j - 1]->GetOp(LEFT);
        }
        *_os << std::endl;
    }
}

void Befunge::OutputUpToDown() {
    for (unsigned i = 0; i < _board.GetWidth(); i++) {
        std::vector<Cell *> column = _board.GetColumnAt(i);
        for (unsigned j = 0; j < column.size(); j++) {
            *_os << column[j]->GetOp(DOWN);
        }
        *_os << std::endl;
    }
}

void Befunge::OutputDownToUp() {
    for (unsigned i = 0; i < _board.GetWidth(); i++) {
        std::vector<Cell *> column = _board.GetColumnAt(i);
        for (unsigned j = column.size(); j > 0; j--) {
            *_os << column[j - 1]->GetOp(UP);
        }
        *_os << std::endl;
    }
}

void Befunge::OutputConstants() {
    *_os << "\t.data\n"
         << ".comm\t" << stringModeLabel << ",8,8\n"
         << charPrintSpecifierLabel << ":\t.asciz\t\"%c\"\n"
         << intPrintSpecifierLabel << ":\t.asciz\t\"%d\"\n"
         << charScanSpecifierLabel << ":\t.asciz\t\"%c\"\n"
         << intScanSpecifierLabel << ":\t.asciz\t\"%d\"\n";
}

