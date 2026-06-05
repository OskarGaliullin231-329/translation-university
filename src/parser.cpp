#include "../include/parser.h"

#include <string>
#include <unordered_set>

typedef std::list<std::pair<std::string, TokenType>> tokens_list;
typedef std::vector<std::pair<std::string, TokenType>> tokens_vector;

std::unordered_set <std::string> keys_type_names {
    "void",
    "int",
    "float",
    "double",
    "char"
};
std::unordered_set<std::string> keys_type_specs {
    "long",
    "short",
    "signed",
    "unsigned"
};
std::unordered_set<std::string> keys_var_specs {
    "const",
    "static",
    "volatile",
    "extern",
    "register"
};
std::unordered_set<std::string> keys_type_wraps {
    "union",
    "auto"
};
std::unordered_set<std::string> keys_switch {
    "switch",
    "case",
    "default"
};
std::unordered_set<std::string> keys_conditions {
    "if",
    "else",
};
std::unordered_set<std::string> keys_loops {
    "for",
    "while",
    "do",
};
std::unordered_set<std::string> keys_lp_management {
    "break",
    "continue"
};
std::unordered_set<std::string> keys_type_decl {
    "struct",
    "typedef",
    "enum"
};
std::unordered_set<std::string> keys_other {
    "return",
    "goto",
    "sizeof"
};

void parse(const tokens_list& tkns_lst, AST& ast) {
    
}
