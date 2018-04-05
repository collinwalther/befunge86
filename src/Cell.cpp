#include "Cell.h"
#include "Befunge.h"
#include <sstream>

char Cell::GetChar() const {
    return _c;
}

bool Cell::IsBridge() const {
    if (GetChar() == '#') {
        return true;
    }
    return false;
}

const Label *Cell::GetLabel(Direction d) const {
    return &(_labels[d]);
}

const Cell *Cell::GetCell(Direction d) const {
    return _cells[d];
}

void Cell::SetCell(Cell *cell, Direction d) {
    _cells[d] = cell;
}

std::string Cell::GetOp(Direction d) const {
    std::ostringstream oss;
    oss << _labels[d] << ":\n"
        << GetASM();
    return oss.str();
}

std::string Cell::GetASM() const {
    Label notStringModeLabel, exitLabel;
    std::ostringstream oss;
    oss << "\tmovq\t" << Befunge::stringModeLabel << ", %rax\n"
        << "\tcmpq\t$0, %rax\n"
        << "\tje  \t" << notStringModeLabel << "\n"
        << GetStringModeASM()
        << "\tjmp \t" << exitLabel << "\n"
        << notStringModeLabel << ":\n"
        << GetNonStringModeASM()
        << exitLabel << ":\n";
    return oss.str();
}

std::string Cell::GetStringModeASM() const {
    std::ostringstream oss;
    oss << "\tpushq\t$" << (int) GetChar() << "\n";
    return oss.str();
}

std::string Addition::GetNonStringModeASM() const {
    std::string answer = "\tpopq\t%rdx\n"
                         "\tpopq\t%rax\n"
                         "\taddl\t%rdx, %rax\n"
                         "\tpushq\t%rax\n";
    return answer;
}

std::string Subtraction::GetNonStringModeASM() const {
    std::string answer = "\tpopq\t%rdx\n"
                         "\tpopq\t%rax\n"
                         "\tsubq\t%rdx, %rax\n"
                         "\tpushq\t%rax\n";
    return answer;
}

std::string Multiplication::GetNonStringModeASM() const {
    std::string answer = "\tpopq\t%rdx\n"
                         "\tpopq\t%rax\n"
                         "\timulq\t%rdx, %rax\n"
                         "\tpushq\t%rax\n";
    return answer;
}

std::string Division::GetNonStringModeASM() const {
    std::string answer = "\tpopq\t%rcx\n"
                         "\tpopq\t%rax\n"
                         "\tcltd\n"
                         "\tidivl\t%rcx\n"
                         "\tpushq\t%rax\n";
    return answer;
}

std::string Modulo::GetNonStringModeASM() const {
    std::string answer = "\tpopq\t%rcx\n"
                         "\tpopq\t%rax\n"
                         "\tcltd\n"
                         "\tidivl\t%rcx\n"
                         "\tpushq\t%rdx\n";
    return answer;
}

std::string Not::GetNonStringModeASM() const {
    std::string answer = "\tpopq\t%rax\n"
                         "\tcmpq\t$0, %rax\n"
                         "\tsete\t%al\n"
                         "\tmovzbl\t%al, %rax\n"
                         "\tpushq\t%rax\n";
    return answer;
}

std::string GreaterThan::GetNonStringModeASM() const {
    std::string answer = "\tpopq\t%rdx\n"
                         "\tpopq\t%rax\n"
                         "\tcmpq\t%rdx, %rax\n"
                         "\tsetg\t%al\n"
                         "\tmovzbl\t%al, %rax\n"
                         "\tpushq\t%rax\n";
    return answer;
}

std::string Right::GetNonStringModeASM() const {
    std::ostringstream oss;
    oss << "\tjmp \t" << *(GetCell(RIGHT)->GetLabel(RIGHT)) << "\n";
    return oss.str();
}

std::string Left::GetNonStringModeASM() const {
    std::ostringstream oss;
    oss << "\tjmp \t" << *(GetCell(LEFT)->GetLabel(LEFT)) << "\n";
    return oss.str();
}

std::string Up::GetNonStringModeASM() const {
    std::ostringstream oss;
    oss << "\tjmp \t" << *(GetCell(UP)->GetLabel(UP)) << "\n";
    return oss.str();
}

std::string Down::GetNonStringModeASM() const {
    std::ostringstream oss;
    oss << "\tjmp \t" << *(GetCell(DOWN)->GetLabel(DOWN)) << "\n";
    return oss.str();
}

std::string Random::GetNonStringModeASM() const {
    //TODO
    return "";
}

std::string HorizontalIf::GetNonStringModeASM() const {
    Label falseLabel;
    std::ostringstream oss;
    oss << "\tpopq\t%rax\n"
        << "\tcmpq\t$0, %rax\n"
        << "\tje  \t" << falseLabel << "\n"
        << "\tjmp \t" << *(GetCell(LEFT)->GetLabel(LEFT)) << "\n"
        << falseLabel << ":\n"
        << "\tjmp \t" << *(GetCell(RIGHT)->GetLabel(RIGHT)) << "\n";
    return oss.str();
}

std::string VerticalIf::GetNonStringModeASM() const {
    Label falseLabel;
    std::ostringstream oss;
    oss << "\tpopq\t%rax\n"
        << "\tcmpq\t$0, %rax\n"
        << "\tje  \t" << falseLabel << "\n"
        << "\tjmp \t" << *(GetCell(UP)->GetLabel(UP)) << "\n"
        << falseLabel << ":\n"
        << "\tjmp \t" << *(GetCell(DOWN)->GetLabel(DOWN)) << "\n";
    return oss.str();
}

std::string StringMode::GetNonStringModeASM() const {
    Label falseLabel, exitLabel;
    std::ostringstream oss;
    oss << "\tmovq\tstringMode, %rax\n"
        << "\tcmpq\t$0, %rax\n"
        << "\tje  \t" << falseLabel << "\n"
        << "\tmovq\t$0, %rax\n"
        << "\tmovq\t%rax, stringMode\n"
        << "\tjmp \t" << exitLabel << "\n"
        << falseLabel << ":\n"
        << "\tmovq\t$1, %rax\n"
        << "\tmovq\t%rax, stringMode\n"
        << exitLabel << ":\n";
    return oss.str();
}

std::string Duplicate::GetNonStringModeASM() const {
    std::string answer = "\tpopq\t%rax\n"
                         "\tpushq\t%rax\n"
                         "\tpushq\t%rax\n";
    return answer;
}

std::string Swap::GetNonStringModeASM() const {
    std::string answer = "\tpopq\t%rax\n"
                         "\tpopq\t%rdx\n"
                         "\tpushq\t%rax\n"
                         "\tpushq\t%rdx\n";
    return answer;
}

std::string Discard::GetNonStringModeASM() const {
    std::string answer = "\tpopq\t%rax\n";
    return answer;
}

std::string PopInt::GetNonStringModeASM() const {
    std::ostringstream oss;
    oss << "\tpopq\t%rsi\n"
        << "\tleaq\t" << Befunge::intPrintSpecifierLabel << "(%rip), %rdi\n"
        << "\tmovq\t$0, %rax\n"
        << "\tcall\tprintf\n";
    return oss.str();
}

std::string PopChar::GetNonStringModeASM() const {
    std::ostringstream oss;
    oss << "\tpopq\t%rsi\n"
        << "\tleaq\t" << Befunge::charPrintSpecifierLabel << "(%rip), %rdi\n"
        << "\tmovq\t$0, %rax\n"
        << "\tcall\tprintf\n";
    return oss.str();
}

std::string Bridge::GetNonStringModeASM() const {
    //TODO
    return "";
}

std::string Get::GetNonStringModeASM() const {
    //TODO
    return "";
}

std::string Put::GetNonStringModeASM() const {
    //TODO
    return "";
}

std::string PushInt::GetNonStringModeASM() const {
    std::ostringstream oss;
    oss << "\tsubq\t$4, %rsp\n"
        << "\tmovq\t%rsp, %rsi\n"
        << "\tleaq\t" << Befunge::intScanSpecifierLabel << "(%rip), %rdi\n"
        << "\tmovq\t$0, %rax\n"
        << "\tcall\tscanf\n";
    return oss.str();
}

std::string PushChar::GetNonStringModeASM() const {
    std::ostringstream oss;
    oss << "\tsubq\t$4, %rsp\n"
        << "\tmovq\t%rsp, %rsi\n"
        << "\tleaq\t" << Befunge::charScanSpecifierLabel << "(%rip), %rdi\n"
        << "\tmovq\t$0, %rax\n"
        << "\tcall\tscanf\n";
    return oss.str();
}

std::string End::GetNonStringModeASM() const {
    std::string answer = "\tmovq\t$0, %rax\n"
                         "\tret\n";
    return answer;
}

std::string Number::GetNonStringModeASM() const {
    std::ostringstream oss;
    oss << "\tpushq\t$" << _number << "\n";
    return oss.str();
}

std::string Space::GetNonStringModeASM() const {
    return "";
}

std::string Error::GetNonStringModeASM() const {
    return "";
}

Number::Number(char c) {
    _c = c;
    _number = c - '0';
}

Cell *CellFactory::GetCell(char c) {
    if (isdigit(c)) {
        return new Number(c);
    }

    switch (c) {
        case '+':   return new Addition(c); break;
        case '-':   return new Subtraction(c); break;
        case '*':   return new Multiplication(c); break;
        case '/':   return new Division(c); break;
        case '%':   return new Modulo(c); break;
        case '!':   return new Not(c); break;
        case '`':   return new GreaterThan(c); break;
        case '>':   return new Right(c); break;
        case '<':   return new Left(c); break;
        case '^':   return new Up(c); break;
        case 'v':   return new Down(c); break;
        case '?':   return new Random(c); break;
        case '_':   return new HorizontalIf(c); break;
        case '|':   return new VerticalIf(c); break;
        case '"':   return new StringMode(c); break;
        case ':':   return new Duplicate(c); break;
        case '\\':  return new Swap(c); break;
        case '$':   return new Discard(c); break;
        case '.':   return new PopInt(c); break;
        case ',':   return new PopChar(c); break;
        case '#':   return new Bridge(c); break;
        case 'g':   return new Get(c); break;
        case 'p':   return new Put(c); break;
        case '&':   return new PushInt(c); break;
        case '~':   return new PushChar(c); break;
        case '@':   return new End(c); break;
        case ' ':   return new Space(c); break;
        default:    return new Error(c); break;
    }
}
