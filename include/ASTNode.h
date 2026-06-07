#ifndef ASTNODE_H_
#define ASTNODE_H_

#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

#include "AST.h"
#include "TokenType.h"
class ASTNode {
public:
    ASTNode(const std::string& value = "");
    bool appendChild(std::shared_ptr<ASTNode>);
    bool removeChild(std::shared_ptr<ASTNode>);
    std::size_t getChildNum();
    auto getChildrenBegin();
    auto getChildrenEnd();
    void setValue(const std::string& value);
    const std::string& getValue() const;
    virtual std::string stringify(std::size_t);

protected:
    // std::size_t _first_token_index = 0;
    // std::size_t _last_token_index = 0;
    std::string _value;
    std::shared_ptr<AST> _AST;
    std::unordered_set<std::shared_ptr<ASTNode>> _children;
};

#endif // ASTNODE_H_
