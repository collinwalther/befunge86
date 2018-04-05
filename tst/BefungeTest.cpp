#include <iostream>
#include <stdexcept>
#include <cassert>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include "Befunge.h"

using namespace std;

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

int Multiply() {
    ifstream ifs("tst/multiply.bf");
    istream& is(ifs);
    ofstream ofs("tst/multiply.s");
    ostream& os(ofs);
    Befunge b(&is, &os);
    b.Run();
    system("gcc -o tst/multiply.out tst/multiply.s");
    string output = RunAndGetStdout("./tst/multiply.out");
    assert(output == "24");
    return 0;
}

int main() {
    Multiply();
    return 0;
}
    
