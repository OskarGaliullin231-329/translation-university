#ifndef ASTNODE_H_
#define ASTNODE_H_

#include <memory>
#include <unordered_set>

#include "NodeTypes.h"

class ASTNode {
public:
    bool addChild(std::shared_ptr<ASTNode>);
    bool removeChild(std::shared_ptr<ASTNode>);
    std::size_t getChildrenNum();
    auto getChildrenBegin();
    auto getChildrenEnd();
    NodeType getNodeType();

protected:
    NodeType _node_type;

private:
    std::unordered_set<std::shared_ptr<ASTNode>> _children;
};

#endif // ASTNODE_H_
