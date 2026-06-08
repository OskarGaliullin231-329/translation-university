#ifndef NODETYPES_H_
#define NODETYPES_H_

enum class NodeType {
    // Statements
    Statement,
    IfStat,
    ElseIfStat,
    ElseStat,
    ForStat,
    WhileStat,
    DoWhileStat,
    ExprStat,
    FuncDefStat,

    // Expressions
    Expression,
    IDExpr,
    LITExpr,
    CallExpr,
    ArithExpr,
    LogicExpr,
    BitwiseExpr,
    PointerExpr,
    AssignExpr,
    CastExpr,
    StructExpr,

    // TypeNodes
    TypeNode,
    BaseTp,
    PointerTp,
    ArrayTp,

    // Declarations
    Declaration,
    VarDecl,
    FuncDecl,
    StructDecl,
    TypeDecl,

    // CodeBlock
    CodeBlock
};

#endif // NODETYPES_H_
