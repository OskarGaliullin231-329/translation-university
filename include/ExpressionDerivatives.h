#ifndef EXPRESSIONDERIVATIVES_H_ 
#define EXPRESSIONDERIVATIVES_H_

#include "Expression.h"

class LitExpr: public Expression {
public:
    std::string stringify(std::size_t) override;
};

class ArithExpr: public Expression {
public:
    std::string stringify(std::size_t) override;
};


class BitwiseExpr: public Expression {
public:
    std::string stringify(std::size_t) override;
};


class LogicExpr: public Expression {
public:
    std::string stringify(std::size_t) override;
};


class PointerExpr: public Expression {
public:
    std::string stringify(std::size_t) override;
};


class FuncCallExpr: public Expression {
public:
    std::string stringify(std::size_t) override;
};


#endif // EXPRESSIONDERIVATIVES_H_
