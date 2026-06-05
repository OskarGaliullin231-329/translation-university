#include "../include/ExpressionDerivatives.h"

std::string LitExpr::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "LitExpr: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string ArithExpr::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "ArithExpr: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string BitwiseExpr::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "BitwiseExpr: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string LogicExpr::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "LogicExpr: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string PointerExpr::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "PointerExpr: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string FuncCallExpr::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "FuncCallExpr: ";
    result += ASTNode::stringify(ident);
    return result;
}
