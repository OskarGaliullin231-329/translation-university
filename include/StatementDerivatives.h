#ifndef STATEMENTDERIVATIVES_H_
#define STATEMENTDERIVATIVES_H_

#include "Statement.h"

// Statements with semicolon in the end
class FuncDecl: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class VarDecl: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class VarInit: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class Typedef: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class LoopMngrs: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class Goto: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class Return: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class ExpresStat: public Statement {
public:
    std::string stringify(std::size_t) override;
};


// Flag for goto with colon in the end
class GTFlag: public Statement {
public:
    std::string stringify(std::size_t) override;
};


// Statements with blocks of code in the end
class FuncDef: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class IfCond: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class ElseCond: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class ElseIfCond: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class Switch: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class SwCase: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class SwDefault: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class For: public Statement {
public:
    std::string stringify(std::size_t) override;
};


class Do: public Statement {
public:
    std::string stringify(std::size_t) override;
};


// While with block of code or semicolon in the end
// in dependency on context (does "while" follow after "do")
class While: public Statement {
public:
    std::string stringify(std::size_t) override;
};


#endif
