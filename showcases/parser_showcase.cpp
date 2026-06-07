#include <iostream>
#include <list>
#include <memory>
#include <string>

#include "../include/ASTNode.h"
#include "../include/lexer.h"
#include "../include/parser.h"

int main() {
    std::string source = R"(
int add(int a, int b) {
    int result = a + b;
    if (result > 0) {
        return result;
    } else {
        return 0;
    }
}

int main() {
    int x = add(1, 2);
    while (x < 10) {
        x = x + 1;
    }
    return x;
}
)";

    std::list<std::pair<std::string, TokenType>> tokens;
    lexer_process(source, tokens);

    auto root = std::make_shared<ASTNode>("translation_unit");
    parse(tokens, root);

    std::cout << root->stringify(0) << std::endl;
    return 0;
}
