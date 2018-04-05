#include "Board.h"
#include <stdexcept>

Board::Board() {
    _height = 0;
    _width = 0;
}

Board::Board(char** b, unsigned width, unsigned height) {
    _height = 0;
    _width = 0;
    for (unsigned i = 0; i < height; i++) {
        std::vector<Cell *> row;
        for (unsigned j = 0; j < width; j++) {
            row.push_back(CellFactory::GetCell(b[i][j]));
        }
        SetRowAt(row, i);
    }
}

std::vector<Cell *> Board::GetRowAt(unsigned rowIndex) {
    if (rowIndex >= GetHeight()) {
        throw std::invalid_argument("Index must be within the bounds of the playing field.");
    }

    std::vector<Cell *> newRow;
    std::vector<Cell *> row = *(GetCells()[rowIndex]);
    for (unsigned i = 0; i < GetWidth(); i++) {
        if (i < row.size()) {
            newRow.push_back(row[i]);
        } else {
            newRow.push_back(CellFactory::GetCell(' '));
        }
    }
    return newRow; 
}

std::vector<Cell *> Board::GetColumnAt(unsigned columnIndex) {
    if (columnIndex >= GetWidth()) {
        throw std::invalid_argument("Index must be within the bounds of the playing field.");
    }

    std::vector<Cell *> col;
    for (unsigned i = 0; i < GetHeight(); i++) {
        if (columnIndex >= _cells[i]->size()) {
            col.push_back(CellFactory::GetCell(' '));
        } else {
            col.push_back((*(_cells[i]))[columnIndex]);
        }
    }
    return col;
}

void Board::SetRowAt(std::vector<Cell *> row, unsigned rowIndex) {
    if (rowIndex < GetHeight()) {
        std::vector<Cell *> *newRow = new std::vector<Cell *>();
        for (unsigned i = 0; i < row.size(); i++) {
            newRow->push_back(row[i]);
        }

        _cells[rowIndex] = newRow;
    } else {
        for (unsigned i = GetHeight(); i < rowIndex; i++) {
            _height++;
            _cells.push_back(new std::vector<Cell *>());
        }
        _height++;
        _cells.push_back(new std::vector<Cell *>(row));
    }

    if (row.size() > GetWidth()) {
        _width = row.size();
    }
}

