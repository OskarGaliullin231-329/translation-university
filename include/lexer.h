#ifndef LEXER_H_
#define LEXER_H_

#include <list>
#include <utility>
#include <string>

#include "TokenType.h"

void lexer_process(const std::string&, std::list<std::pair<std::string, TokenType>>&);

#endif // LEXER_H_
