#ifndef PARSER_H_
#define PARSER_H_

#include <list>
#include <vector>
#include <utility>

#include "CodeBlock.h"
#include "DeclarationDerivatives.h"
#include "ExpressionDerivatives.h"
#include "StatementDerivatives.h"
#include "TypeNodeDerivatives.h"
#include "TokenType.h"

class Parser {
public:
    Parser(std::shared_ptr<ASTNode>);
    bool parse(const std::list<std::pair<std::string, TokenType>>&);

private:
    std::vector<std::pair<std::string, TokenType>> _tkns_vctr;
    std::shared_ptr<ASTNode> _root_node;
};

#endif // PARSER_H_
