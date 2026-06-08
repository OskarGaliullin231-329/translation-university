#ifndef EXPRESSIONDERIVATIVES_H_
#define EXPRESSIONDERIVATIVES_H_

#include "Expression.h"

// Leaf Expressions

// contains only identificator
class IDExpr: public Expression {
public:
    IDExpr() { _node_type = NodeType::IDExpr; }
    void setTokenIndex(std::size_t index) { _token_i = index; }
    std::size_t getTokenIndex() { return _token_i; }

private:
    std::size_t _token_i;
};

// contains only literal
class LITExpr: public Expression {
public:
    LITExpr() { _node_type = NodeType::LITExpr; }
    void setTokenIndex(std::size_t index) { _token_i = index; }
    std::size_t getTokenIndex() { return _token_i; }

private:
    std::size_t _token_i;
};

// <IDExpr>(Expression, Expression, Expression, ...)
// sizeof(Expression, Expression, Expression, ...)
class CallExpr: public Expression {
public:
    CallExpr() { _node_type = NodeType::CallExpr; }
    void setTokenIndex(std::size_t index) { _token_i = index; }
    std::size_t getTokenIndex() { return _token_i; }

private:
    std::size_t _token_i;
};


// Branch Expressions

// contains arithmetic operators
class ArithExpr: public Expression {
public:
    ArithExpr() { _node_type = NodeType::ArithExpr; }
};

// contains logical operators
class LogicExpr: public Expression {
public:
    LogicExpr() { _node_type = NodeType::LogicExpr; }
};

// contains bitwise operators
class BitwiseExpr: public Expression {
public:
    BitwiseExpr() { _node_type = NodeType::BitwiseExpr; }
};

// contains unary pointer operators
class PointerExpr: public Expression {
public:
    PointerExpr() { _node_type = NodeType::PointerExpr; }
};

// contains all types of assigning operators
class AssignExpr: public Expression {
public:
    AssignExpr() { _node_type = NodeType::AssignExpr; }
};

// (<TypeNode>)IDExpr
// (<TypeNode>)LITExpr
// (<TypeNode>)CallExpr
class CastExpr: public Expression {
public:
    CastExpr() { _node_type = NodeType::CastExpr; }
};

// <IDExpr>.<IDExpr>
// <IDExpr>-><IDExpr>
class StructExpr: public Expression {
public:
    StructExpr() { _node_type = NodeType::StructExpr; }
};

#endif // EXPRESSIONDERIVATIVES_H_

