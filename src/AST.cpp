#include "../include/AST.h"

AST::AST(std::shared_ptr<ASTNode> root_node) {
    _root_node = root_node;
}

bool AST::setToken(std::size_t index, const std::pair<std::string, TokenType>& token_pair) {
    if (index >= _tkns_vctr.size()) {
        return false;
    }
    _tkns_vctr[index] = token_pair;
    return true;
}

std::size_t AST::getTokensNum() {
    return _tkns_vctr.size();
}

std::pair<std::string, TokenType> AST::getToken(std::size_t index) {
    if (index >= _tkns_vctr.size()) {
        std::pair<std::string, TokenType> err_pair{"", TokenType::ID};
        return err_pair;
    }
    return _tkns_vctr[index];
}

