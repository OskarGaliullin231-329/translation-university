#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "ASTNode.h"

class Expression: public ASTNode {
public:
    Expression() { _node_type = NodeType::Expression; }
};

#endif // EXPRESSION_H_
