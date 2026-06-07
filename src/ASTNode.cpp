#include "../include/ASTNode.h"

ASTNode::ASTNode(const std::string& value)
    : _value(value)
{
}

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

void ASTNode::setValue(const std::string& value) {
    _value = value;
}

const std::string& ASTNode::getValue() const {
    return _value;
}

std::string ASTNode::stringify(std::size_t indent) {
    std::string result(indent, ' ');
    if (!_value.empty()) {
        result += _value;
    }
    if (_children.empty()) {
        return result;
    }
    if (!_value.empty()) {
        result += "\n";
    }
    bool first = true;
    for (auto child : _children) {
        if (!first) {
            result += "\n";
        }
        result += child->stringify(indent + 2);
        first = false;
    }
    return result;
}
