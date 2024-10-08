#ifndef SCP_INSTANCE
#define SCP_INSTANCE

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

const std::string DATA_PATH = "SCP_DATASET/instances/";

class scp_instance {
  public:
    int rows, cols;
    std::vector<double> w; // weights (costs) of columns
    std::vector<std::set<int>> S; // vector of sets. set 's' on position 'n' means that
                                  // n-th row is covered by columns in 's'
    bool read_file(char* fname);
};


inline bool scp_instance::read_file(char* fname){
    
    std::ifstream input_file(fname);

    if (!input_file.is_open()) {
        return false;
    }

    int i, j, covered_by_n, column_it;
    
    input_file >> rows;
    input_file >> cols;
    
    w.resize(cols);
    S.resize(rows);

    for (i = 0; i < cols; ++i) {
        input_file >> w[i];
    }

    for (i = 0; i < rows; ++i) {
        input_file >> covered_by_n;
        for (j = 0; j < covered_by_n; ++j) {
            input_file >> column_it;
            S[i].insert(column_it-1);
        }
    }

    input_file.close();
    return true;
}

#endif