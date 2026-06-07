#ifndef TOKENTYPE_H_
#define TOKENTYPE_H_

#include <cstdint>

enum class TokenType {
    ID,
    KEY,
    DEL,
    OP,
    LIT
};


struct TTClass {
    u_int8_t ID  = 0b0;
    u_int8_t KEY = 0b0;
    u_int8_t DEL = 0b0;
    u_int8_t OP  = 0b0;
    u_int8_t LIT = 0b0;
};

/*
Last bit of field TTClass type is responsible for belonging to type.
Every next bit is responsible for belonging to subtype of lexem.
For example "ID = 0b101" stands for identrificator of function name.  
*/

// enum class ID {
//     VarName,
//     FuncName,
//     TypeName
// };

// enum class KeyWord {
//     TypeName,
//     TypeSpec,
//     VarSpec,
//     TypeWrap,
//     SwPart,
//     CondPart,
//     Loop,
//     LpManag,
//     TypeDecl,
//     Other
// };

// enum class Delim {
//     InterToken,
//     SemiCol,
//     Comma,
//     ParRnd,
//     ParFig,
//     ParSq
// };

// enum class OperByArgNum {
//     Unary,
//     Binary,
//     Ternary
// };

// enum class OperByUse {
//     Assign,
//     Value
// };

// enum class OperByPurp {
//     Arith,
//     Logic,
//     BitLogic,
//     IncDec,
//     Struct,
//     Comp
// };

// enum class Liter {
//     Num,
//     Char,
//     Str
// };

#endif // TOKENTYPE_H_
