#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

#include "include/preprocessor.h"
#include "include/utility_funcs.h"

int main(int argc, char* argv[]) {
    std::vector<std::string> args_vec;
    get_cmd_args(argc, argv, args_vec);
    if (args_vec.size() < 2) {
        std::cout << "You didn't specify name of the source file.\n";
        return 1;
    }
    std::ifstream src_file(args_vec[1]);
    std::string src_contents = read(src_file);
    std::string prep_src_contents = preprocessed(src_contents);
    std::cout << prep_src_contents << '\n';
    return 0;
}
