#include "../include/Statement.h"

std::string Statement::stringify(std::size_t ident) {
    std::string result("Statement: \n");
    result += ASTNode::stringify(ident);
    return result;
}
