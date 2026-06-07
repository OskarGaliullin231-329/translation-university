#ifndef PARSER_H_
#define PARSER_H_

#include <list>
#include <string>
#include <utility>
#include <vector>

#include "ASTNode.h"
#include "TokenType.h"

class Parser {
public:
    void parse();

private:
    std::vector<std::pair<std::string, TokenType>> _tokens;
};

#endif // PARSER_H_
