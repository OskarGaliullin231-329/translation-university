#include "../include/ASTStringifier.h"

void ASTStringifier::stringify() {
    for (auto iter = _root_node->getChildrenBegin(); 
         iter != _root_node->getChildrenEnd(); 
         iter++) {
        std::shared_ptr<ASTNode> curr_node = *iter;
        switch (curr_node->getNodeType()) {
            
        }
    }
}
