#include "Befunge.h"
#include <vector>
#include <iostream>

void Befunge::GetCellsFromLines() {
    // Read stdin until EOF
    int lineNumber = 0;
    while (true) {
        // Read the line:
        std::string line;
        getline(std::cin, line);

        // For every character in the line, create a
        // cell from it and push it onto our cells.
        std::vector<Cell *> row;
        for (int i = 0; i < line.size(); i++) {
            row.push_back(new Cell(line[i]));
        }
        _board.SetRowAt(row, lineNumber);
        lineNumber++;

        // If EOF was encountered while getting this line,
        // then stop reading lines.
        if (std::cin.eof()) {
            break;
        }
    }
}

void Befunge::Run() {
    GetCellsFromLines();

    for (int i = 0; i < _board.GetHeight(); i++) {
        std::vector<Cell *> row = _board.GetRowAt(i);
        for (int i = 0; i < row.size(); i++) {
            std::cout << *(row[i]);
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < _board.GetWidth(); i++) {
        std::vector<Cell *> column = _board.GetColumnAt(i);
        for (int i = 0; i < column.size(); i++) {
            std::cout << *(column[i]);
        }
        std::cout << std::endl;
    }
}
