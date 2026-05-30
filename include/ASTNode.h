#ifndef ASTNODE_H_
#define ASTNODE_H_

#include <memory>
#include <vector>

class ASTNode {
public:
    bool appendChild(const ASTNode&) const;
    std::size_t getChildNum();

protected:
    std::vector<std::shared_ptr<ASTNode>> _children;
};

#endif // ASTNODE_H_
