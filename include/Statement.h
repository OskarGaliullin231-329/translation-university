#ifndef STATEMENT_H_
#define STATEMENT_H_

#include <string>

#include "ASTNode.h"

class Statement: public ASTNode {
public:
    virtual std::string stringify(std::size_t) override;
};

#endif // STATEMENT_H_
