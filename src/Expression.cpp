#include "../include/Expression.h"

std::string Expression::stringify(std::size_t ident) {
    std::string result("Expression: \n");
    result += ASTNode::stringify(ident);
    return result;
}
