#ifndef TYPENODEDERIVATIVES_H_
#define TYPENODEDERIVATIVES_H_

#include "TypeNode.h"

// <base type>
class BaseTp: public TypeNode {
public:
    BaseTp() { _node_type = NodeType::BaseTp; }
};

// <base type>*
class PointerTp: public TypeNode {
public:
    PointerTp() { _node_type = NodeType::PointerTp; }
};

// <base type>[]
// <base type>[<ID>]
class ArrayTp: public TypeNode {
public:
    ArrayTp() { _node_type = NodeType::ArrayTp; }
};

#endif // TYPENODEDERIVATIVES_H_
