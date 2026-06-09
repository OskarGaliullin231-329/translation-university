#include <fstream>
#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>

#include "ASTStringifier.h"
#include "lexer.h"
#include "Parser.h"
#include "preprocessor.h"
#include "utility_funcs.h"

int main(int argc, char* argv[]) {
    std::vector<std::string> cmd_args;
    get_cmd_args(argc, argv, cmd_args);
    if (cmd_args.size() < 2) {
        std::cerr << "You didn't specify name of the source file.\n";
        return 1;
    }
    else if (cmd_args.size() == 2) {
        std::ifstream file(cmd_args[1]);
        if (!file.good()) {
            std::cerr << "No such file: " << cmd_args[1] << ".\n";
            return 1;
        }

        std::string contents = read(file);
        std::string preproc = preprocessed(contents);
        std::list<std::pair<std::string, TokenType>> tokens;
        lexer_process(preproc, tokens);

        auto root = std::make_shared<CodeBlock>();
        Parser parser(root);
        bool ok = parser.parse(tokens);

        ASTStringifier ast_stringifier = ASTStringifier(root);
        ast_stringifier.stringify();
        std::cout << ast_stringifier.getResult() << '\n';
    }
    else {
        std::cerr << "Too much argumets given.\n";
        return 1;
    }
    return 0;
}
