#include "../include/utility_funcs.h"

#include <fstream>
#include <string>
#include <vector>

std::string read(std::ifstream& file) {
    std::string result;
    std::string line;
    while (getline(file, line)) { result += line + '\n'; }
    return result;
}

void get_cmd_args(int argc, char** argv, std::vector<std::string>& args_vector) {
    for (int i = 0; i < argc; i++) {
        args_vector.push_back(argv[i]);
    }
}
