#include "../include/ASTNode.h"

bool ASTNode::appendChild(std::shared_ptr<ASTNode> node_ptr) {
    if (_children.contains(node_ptr)) {
        return false;
    }
    _children.insert(node_ptr);
    return true;
}

bool ASTNode::removeChild(std::shared_ptr<ASTNode> node_ptr) {
    if (!_children.contains(node_ptr)) {
        return false;
    }
    _children.erase(node_ptr);
    return true;
}

std::size_t ASTNode::getChildNum() {
    return _children.size();
}

auto ASTNode::getChildrenBegin() {
    return _children.begin();
}

auto ASTNode::getChildrenEnd() {
    return _children.end();
}

std::string ASTNode::stringify(std::size_t indent) {
    if (_children.empty()) {
        return "";
    }
    std::string result(indent, ' ');
    for (auto child : _children) {
        result += (child->stringify(indent + 2) + "\n");
    }
    return result;
}
