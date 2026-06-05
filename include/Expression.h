#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "ASTNode.h"

class Expression: public ASTNode {
public:
    virtual std::string stringify(std::size_t) override;
};

#endif // EXPRESSION_H_
