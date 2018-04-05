#ifndef CELL_H
#define CELL_H

#include "Label.h"
#include <iostream>

enum Direction { LEFT, RIGHT, DOWN, UP};

class Cell {
  protected:
    char _c;
    Label _labels[4];
    Cell *_cells[4];
    virtual std::string GetNonStringModeASM() const;
    virtual std::string GetNonStringModeASM(Direction d) const;
    virtual std::string GetStringModeASM() const; 
    virtual std::string GetASM(Direction d) const;

  public:
    char GetChar() const;
    bool IsBridge() const;
    const Label *GetLabel(Direction d) const;
    const Cell *GetCell(Direction d) const;
    void SetCell(Cell *cell, Direction d);
    std::string GetOp(Direction d) const;
};

class Addition : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Addition(char c) { _c = c; }
};

class Subtraction : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Subtraction(char c) { _c = c; }
};

class Multiplication : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Multiplication(char c) { _c = c; }
};

class Division : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Division(char c) { _c = c; }
};

class Modulo : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Modulo(char c) { _c = c; }
};

class Not : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Not(char c) { _c = c; }
};

class GreaterThan : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    GreaterThan(char c) { _c = c; }
};

class Right : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Right(char c) { _c = c; }
};

class Left : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Left(char c) { _c = c; }
};

class Up : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Up(char c) { _c = c; }
};

class Down : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Down(char c) { _c = c; }
};

class Random : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Random(char c) { _c = c; }
};

class HorizontalIf : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    HorizontalIf(char c) { _c = c; }
};

class VerticalIf : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    VerticalIf(char c) { _c = c; }
};

class StringMode : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    StringMode(char c) { _c = c; }
};

class Duplicate : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Duplicate(char c) { _c = c; }
};

class Swap : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Swap(char c) { _c = c; }
};

class Discard : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Discard(char c) { _c = c; }
};

class PopInt : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    PopInt(char c) { _c = c; }
};

class PopChar : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    PopChar(char c) { _c = c; }
};

class Bridge : public Cell {
  private:
    std::string GetNonStringModeASM(Direction d) const;

  public:
    Bridge(char c) { _c = c; }
};

class Get : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Get(char c) { _c = c; }
};

class Put : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Put(char c) { _c = c; }
};

class PushInt : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    PushInt(char c) { _c = c; }
};

class PushChar : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    PushChar(char c) { _c = c; }
};

class End : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    End(char c) { _c = c; }
};

class Number : public Cell {
  private:
    unsigned short _number;
    std::string GetNonStringModeASM() const;

  public:
    Number(char c);
};

class Space : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Space(char c) { _c = c; }
};

class Error : public Cell {
  private:
    std::string GetNonStringModeASM() const;

  public:
    Error(char c) { _c = c; }
};

class CellFactory {
  private:
    CellFactory();

  public:
    static Cell *GetCell(char c);
};

#endif
