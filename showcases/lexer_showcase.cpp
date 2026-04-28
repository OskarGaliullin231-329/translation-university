#include <fstream>
#include <list>
#include <iostream>
#include <utility>
#include <vector>

#include <lexer.h>
#include <preprocessor.h>
#include <utility_funcs.h>


void print_token_list(const std::list<std::pair<std::string, TokenType>>& output_list) {
    std::cout << "List of Tokens:\n";
    for (auto pr : output_list) {
        std::cout << '"' << pr.first << '"' << ' ';
        switch (pr.second) {
            case TokenType::ID: {
                std::cout << ", ID\n";
                break;
            }
            case TokenType::KEY: {
                std::cout << ", KEY\n";
                break;
            }
            case TokenType::DEL: {
                std::cout << ", DEL\n";
                break;
            }
            case TokenType::LIT: {
                std::cout << ", LIT\n";
                break;
            }
            case TokenType::OP: {
                std::cout << ", OP\n";
                break;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::vector<std::string> cmd_args;
    get_cmd_args(argc, argv, cmd_args);
    if (cmd_args.size() < 2) {
        std::cerr << "You didn't specify name of the source file.\n";
        return 1;
    }
    else if (cmd_args.size() == 2) {
        std::ifstream file(cmd_args[1]);
        if (file.good()) {
            std::string str = preprocessed(read(file));
            std::list<std::pair<std::string, TokenType>> output_list;
            lexer_process(str, output_list);
            print_token_list(output_list);
        }
        else {
            std::cerr << "No such file: " << cmd_args[1] << ".\n";
        }
    }
    else {
        std::cerr << "Too much argumets given.\n";
        return 1;
    }
    return 0;
}
