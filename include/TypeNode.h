#ifndef TYPENODE_H_
#define TYPENODE_H_

#include "ASTNode.h"

// Leaf node

// [<variable specifier> <type specifier>] <builtin type>
// [<variable specifier>] <type wraper>
// [<variable specifier>] <user defined type>
class TypeNode: public ASTNode {
public:
    TypeNode() { _node_type = NodeType::TypeNode; }
    void setFirstTokenIndex(std::size_t index) { _first_token_i = index; }
    void setLastTokenIndex(std::size_t index) { _last_token_i = index; }
    std::size_t getFirstTokenIndex() { return _first_token_i; }
    std::size_t getLastTokenIndex() { return _last_token_i; }

private:
    std::size_t _first_token_i;
    std::size_t _last_token_i;
};

#endif // TYPENODE_H_
