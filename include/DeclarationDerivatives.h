#ifndef DECLARATIONDERIVATIVES_H_
#define DECLARATIONDERIVATIVES_H_

#include "Declaration.h"

/*
We will only specify assign epressions here in order to reduce amount of text.
*/

// <TypeNode> <IDExpr> = <Expression>;
class VarDecl: public Declaration {
public:
    VarDecl() { _node_type = NodeType::VarDecl; }
};

// <TypeNode> <IDExpr>(<VarDecl>, <VarDecl>, <VarDecl>, ...);
// <TypeNode> <IDExpr>(<TypeNode>, <TypeNode>, <TypeNode>, ...);
class FuncDecl: public Declaration {
public:
    FuncDecl() { _node_type = NodeType::FuncDecl; }
};

// struct <IDExpr> <CodeBlock>;
class StructDecl: public Declaration {
public:
    StructDecl() { _node_type = NodeType::StructDecl; }
    void setTokenIndex(std::size_t index) { _token_i = index; }
    std::size_t getTokenIndex() { return _token_i; }

private:
    std::size_t _token_i;
};

// typedef <TypeNode> <IDExpr>;
class TypeDecl: public Declaration {
public:
    TypeDecl() { _node_type = NodeType::TypeDecl; }
    void setTokenIndex(std::size_t index) { _token_i = index; }
    std::size_t getTokenIndex() { return _token_i; }

private:
    std::size_t _token_i;

};

#endif // DECLARATIONDERIVATIVES_H_
