#include "../include/ASTNode.h"

bool ASTNode::addChild(std::shared_ptr<ASTNode> node_ptr) {
    bool result = true;
    if (!_children.contains(node_ptr)) {
        _children.insert(node_ptr);
    }
    else {
        result = false;
    }
    return result;
}

bool ASTNode::removeChild(std::shared_ptr<ASTNode> node_ptr) {
    bool result = true;
    if (_children.contains(node_ptr)) {
        _children.erase(node_ptr);
    }
    else {
        result = false;
    }
    return result;
}

std::size_t ASTNode::getChildrenNum() {
    return _children.size();
}

auto ASTNode::getChildrenBegin() {
    return _children.begin();
}

auto ASTNode::getChildrenEnd() {
    return _children.end();
}

NodeType ASTNode::getNodeType() {
    return _node_type;
}
