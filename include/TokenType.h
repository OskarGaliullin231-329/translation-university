#ifndef TOKENYPE_H_
#define TOKENYPE_H_

enum class TokenType {
    ID,
    KEY,
    DEL,
    OP,
    LIT
};

enum class ID {
    VarName,
    FuncName,
    TypeName
};

enum class KeyWord {
    TypeName,
    TypeSpec,
    VarSpec,
    TypeWrap,
    SwPart,
    CondPart,
    Loop,
    LpManag,
    TypeDecl,
    Other
};

enum class Delim {
    InterToken,
    SemiCol,
    Comma,
    ParRnd,
    ParFig,
    ParSq
};

enum class OperByArgNum {
    Unary,
    Binary,
    Ternary
};

enum class OperByUse {
    Assign,
    Value
};

enum class OperByPurp {
    Arith,
    Logic,
    BitLogic,
    IncDec,
    Struct,
    Comp
};

enum class Liter {
    Num,
    Char,
    Str
};

#endif // TOKENYPE_H_
