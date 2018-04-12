#include "Befunge.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Usage: befunge <input file> <output file>" << endl;
        return 1;
    }

    ifstream ifs(argv[1]);
    ofstream ofs(argv[2]);

    Befunge b(&ifs, &ofs);
    b.Run();
}
