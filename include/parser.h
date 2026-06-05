#ifndef PARSER_H_
#define PARSER_H_

#include <list>
#include <memory>
#include <string>
#include <utility>

#include "ASTNode.h"
#include "TokenType.h"

void parse(const std::list<std::pair<std::string, TokenType>>&, std::shared_ptr<ASTNode>);

#endif // PARSER_H_
