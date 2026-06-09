#ifndef ASTSTRINGIFIER_H_
#define ASTSTRINGIFIER_H_

#include <memory>
#include <string>

#include "DeclarationDerivatives.h"
#include "ExpressionDerivatives.h"
#include "NodeTypes.h"
#include "StatementDerivatives.h"
#include "TypeNodeDerivatives.h"

class ASTStringifier {
public:
    ASTStringifier(const std::shared_ptr<ASTNode> root_node) { _root_node = root_node; }
    void stringify();
    std::string getResult() { return _result; }

private:
    std::shared_ptr<ASTNode> _root_node;
    std::string _result;
};

#endif // ASTSTRINGIFIER_H_
