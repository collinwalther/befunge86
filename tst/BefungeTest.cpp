#include <iostream>
#include <stdexcept>
#include <cassert>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include "Befunge.h"

using namespace std;

string RunAndGetStdout(const char* cmd);
int TestOneCase(string name, string expected);
int Multiply(); 

int main() {
    Multiply();
    return 0;
}

int Multiply() {
    TestOneCase("multiply", "24");
    return 0;
}

string RunAndGetStdout(const char* cmd) {
    char buffer[128];
    string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw runtime_error("popen() failed!");
    try {
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

int TestOneCase(string name, string expected) {
    stringstream bfPathStream, asmPathStream, execPathStream;
    bfPathStream << "tst/" << name << ".bf";
    asmPathStream << "tst/" << name << ".s";
    execPathStream << "tst/" << name << ".out";

    string bfPath = bfPathStream.str();
    string asmPath = asmPathStream.str();
    string execPath = execPathStream.str();

    ifstream ifs(bfPath.c_str());
    istream& is(ifs);
    
    ofstream ofs(asmPath.c_str());
    ostream& os(ofs);
    
    Befunge b(&is, &os);
    b.Run();

    stringstream compileStream;
    compileStream << "gcc -o " << execPath << " " << asmPath;

    string compileCommand = compileStream.str();
    system(compileCommand.c_str());

    string result = RunAndGetStdout(execPath.c_str());
    assert(result == expected);

    return 0;
}

