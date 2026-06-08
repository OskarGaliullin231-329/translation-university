#ifndef CODEBLOCH_H_
#define CODEBLOCH_H_

#include "ASTNode.h"

/*
CodeBlock contains only statements and other CodeBlocks.
*/

class CodeBlock: public ASTNode {
public:
    CodeBlock() { _node_type = NodeType::CodeBlock; }
};

#endif // CODEBLOCH_H_
