#include "scp_instance.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <stdexcept>
#include <cstdlib>
#include <ctime>


int main (int argc, char* argv []) {

    if (argc > 1) {
        std::cout << "INF: filename specified: " << argv[1] << std::endl;
    }
    else {
        std::cout << "ERR: please provide a file with SCP instance as an argument" << std::endl;
        return 0;
    }

    char* inst_fname = argv[1];
    
    scp_instance inst;
    if (inst.read_file(inst_fname, false)) {
        std::cout << "INF: Reading successful. Instance with " << inst.rows << " rows and " << inst.cols << " columns loaded" << std::endl;
    }
    else {
        std::cout << "ERR: Could not open file at '" << inst_fname << "'. Maybe it does not exist, or is somewhere else" << std::endl;
        return 0;
    }

    return 0;
}