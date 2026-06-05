#include "../include/StatementDerivatives.h"

std::string FuncDecl::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "FuncDecl: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string VarDecl::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "VarDecl: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string VarInit::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "VarInit: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string Typedef::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "Typedef: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string LoopMngrs::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "LoopMngrs: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string Goto::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "Goto: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string Return::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "Return: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string ExpresStat::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "ExpresStat: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string GTFlag::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "GTFlag: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string FuncDef::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "FuncDef: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string IfCond::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "IfCond: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string ElseCond::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "ElseCond: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string ElseIfCond::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "ElseIfCond: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string Switch::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "Switch: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string SwCase::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "SwCase: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string SwDefault::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "SwDefault: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string For::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "For: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string Do::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "Do: ";
    result += ASTNode::stringify(ident);
    return result;
}

std::string While::stringify(std::size_t ident) {
    std::string result(ident, ' ');
    result += "While: ";
    result += ASTNode::stringify(ident);
    return result;
}
