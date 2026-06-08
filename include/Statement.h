#ifndef STATEMENT_H_
#define STATEMENT_H_

#include "ASTNode.h"

class Statement: public ASTNode {
public:
    Statement() { _node_type = NodeType::Statement; }
};

#endif // STATEMENT_H_
