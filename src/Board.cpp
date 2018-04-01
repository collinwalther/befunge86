#include "Board.h"

Board::Board() {
    _height = 0;
    _width = 0;
}

Board::Board(char** b, int width, int height) {
    _height = 0;
    _width = 0;
    for (int i = 0; i < height; i++) {
        std::vector<Cell *> row;
        for (int j = 0; j < width; j++) {
            row.push_back(new Cell(b[i][j]));
        }
        SetRowAt(row, i);
    }
}

std::vector<Cell *> Board::GetRowAt(int rowIndex) {
    if (rowIndex < 0 || rowIndex >= GetHeight()) {
        throw std::invalid_argument("Index must be within the bounds of the playing field.");
    }

    std::vector<Cell *> newRow;
    std::vector<Cell *> row = *(GetCells()[rowIndex]);
    for (int i = 0; i < GetWidth(); i++) {
        if (i < row.size()) {
            newRow.push_back(row[i]);
        } else {
            newRow.push_back(new Cell(' '));
        }
    }
    return newRow; 
}

std::vector<Cell *> Board::GetColumnAt(int columnIndex) {
    if (columnIndex < 0 || columnIndex >= GetWidth()) {
        throw std::invalid_argument("Index must be within the bounds of the playing field.");
    }

    std::vector<Cell *> col;
    for (int i = 0; i < GetHeight(); i++) {
        if (columnIndex >= _cells[i]->size()) {
            col.push_back(new Cell(' '));
        } else {
            col.push_back((*(_cells[i]))[columnIndex]);
        }
    }
    return col;
}

void Board::SetRowAt(std::vector<Cell *> row, int rowIndex) {
    if (rowIndex < 0) {
        throw std::invalid_argument("New row must have an index greater than or equal to 0.");
    } else if (rowIndex < GetHeight()) {
        std::vector<Cell *> *newRow = new std::vector<Cell *>();
        for (int i = 0; i < row.size(); i++) {
            newRow->push_back(row[i]);
        }

        _cells[rowIndex] = newRow;
    } else {
        for (int i = GetHeight(); i < rowIndex; i++) {
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

