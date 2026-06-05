#ifndef AST_H_
#define AST_H_

#include <memory>
#include <utility>
#include <vector>

#include "TokenType.h"

class AST {
public:
    class ASTNode;

    AST(std::shared_ptr<ASTNode>);
    bool setToken(std::size_t, const std::pair<std::string, TokenType>&);
    std::size_t getTokensNum();
    std::pair<std::string, TokenType> getToken(std::size_t);

private:
    std::vector<std::pair<std::string, TokenType>> _tkns_vctr;
    std::shared_ptr<ASTNode> _root_node;
};

#endif // AST_H_
