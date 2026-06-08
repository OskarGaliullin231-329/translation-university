#ifndef DECLARATION_H_
#define DECLARATION_H_

#include "ASTNode.h"


// <TypeNode> <AssignExpr>;
class Declaration: public ASTNode {
public:
    Declaration() { _node_type = NodeType::Declaration; }
};

#endif // DECLARATION_H_
