#ifndef STATEMENTDERIVATIVES_H_
#define STATEMENTDERIVATIVES_H_

#include "DeclarationDerivatives.h"
#include "ExpressionDerivatives.h"
#include "Statement.h"

// if (LogicExpr) <CodeBlock>
class IfStat: public Statement {
public:
    IfStat() { _node_type = NodeType::IfStat; }
    void setTokenIndex(std::size_t index) { _token_i = index; }
    std::size_t getTokenIndex() { return _token_i; }

private:
    std::size_t _token_i;
};

// else if (LogicExpr) <CodeBlock>
class ElseIfStat: public Statement {
public:
    ElseIfStat() { _node_type = NodeType::ElseIfStat; }
    void setIfIndex(std::size_t index) { _if_token_i = index; }
    void setElseIndex(std::size_t index) { _else_token_i = index; }
    std::size_t getIfIndex() { return _if_token_i; }
    std::size_t getElseIndex() { return _else_token_i; }

private:
    std::size_t _if_token_i;
    std::size_t _else_token_i;
};

// else <CodeBlock>
class ElseStat: public Statement {
public:
    ElseStat() { _node_type = NodeType::ElseStat; }
    void setTokenIndex(std::size_t index) { _token_i = index; }
    std::size_t getTokenIndex() { return _token_i; }

private:
    std::size_t _token_i;
};

// for (<VarDecl>, <LogicExpr>, <Expr>) <CodeBlock>
// for (<IDExpr>, <LogicExpr>, <Expr>) <CodeBlock>
class ForStat: public Statement {
public:
    ForStat() { _node_type = NodeType::ForStat; }
    void setTokenIndex(std::size_t index) { _token_i = index; }
    std::size_t getTokenIndex() { return _token_i; }

private:
    std::size_t _token_i;
};

// while (<LogicExpr>) <CodeBlock>
class WhileStat: public Statement {
public:
    WhileStat() { _node_type = NodeType::WhileStat; }
    void setTokenIndex(std::size_t index) { _token_i = index; }
    std::size_t getTokenIndex() { return _token_i; }

private:
    std::size_t _token_i;
};

// do <CodeBlock> while (<LogicExpr>);
class DoWhileStat: public Statement {
public:
    DoWhileStat() { _node_type = NodeType::DoWhileStat; }
    void setDoIndex(std::size_t index) { _do_token_i = index; }
    void setWhileIndex(std::size_t index) { _while_token_i = index; }
    std::size_t getDoIndex() { return _do_token_i; }
    std::size_t getWhileindex() { return _while_token_i; }

private:
    std::size_t _do_token_i;
    std::size_t _while_token_i;
};

// <Expression>;
class ExprStat: public Statement {
public:
    ExprStat() { _node_type = NodeType::ExprStat; }
};

// <TypeNode> <IDExpr>(<VarDecl>, <VarDecl>, <VarDecl>, ...)
class FuncDefStat: public Statement {
public:
    FuncDefStat() { _node_type = NodeType::FuncDefStat; }
};

#endif // STATEMENTDERIVATIVES_H_
