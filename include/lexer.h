#ifndef LEXER_H_
#define LEXER_H_

#include <list>
#include <utility>
#include <string>

enum class TokenType {
    ID,
    KEY,
    DEL,
    OP,
    LIT
};

void lexer_process(const std::string&, std::list<std::pair<std::string, TokenType>>&);

#endif // LEXER_H_
