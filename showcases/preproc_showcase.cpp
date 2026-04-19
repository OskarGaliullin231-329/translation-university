#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

#include "preprocessor.h"
#include "utility_funcs.h"

int main(int argc, char* argv[]) {
    std::vector<std::string> args_vec;
    get_cmd_args(argc, argv, args_vec);
    if (args_vec.size() < 2) {
        std::cerr << "You didn't specify name of the source file.\n";
        return 1;
    }
    // std::cout << preped_src_contents;
    else if (args_vec.size() == 2) {
        std::ifstream src_file(args_vec[1]);
        if (src_file.good()) {
            std::string src_contents = read(src_file);
            std::string preped_src_contents = preprocessed(src_contents);
            std::ofstream preped_file("src-out/preped_" + args_vec[1]);
            preped_file << preped_src_contents << '\n';
        }
        else {
            std::cerr << "There is no file located by given path.\n";
        }
        src_file.close();
    }
    else {
        std::cerr << "Too much argumets given.\n";
        return 1;
    }
    
    return 0;
}
