#include "../include/Parser.h"

#include <string>
#include <array>

Parser::Parser(std::shared_ptr<ASTNode> root_node) {
    _root_node = root_node;
}

bool Parser::parse(const std::list<std::pair<std::string, TokenType>>& tokens_list) {
    bool result = true;
    _tkns_vctr.reserve(tokens_list.size());
    for (const auto& pr : tokens_list) { _tkns_vctr.push_back(pr); }
    std::array<std::string, 5> types {
        "void", "int", "float", "double", "char"
    };
    std::array<std::string, 4> type_specifiers {
        "long", "short", "signed", "unsigned"
    };
    std::array<std::string, 5> variable_specifiers {
        "const", "static", "volatile", "extern", "register"
    };
    std::array<std::string, 2> type_wrapers {
        "union", "auto"
    };
    std::array<std::string, 3> switch_case_keywords {
        "switch", "case", "default"
    };
    std::array<std::string, 2> condition_keywords {
        "if", "else"
    };
    std::array<std::string, 3> loop_keywords {
        "for", "while", "do"
    };
    std::array<std::string, 2> loop_management_keywords {
        "break", "continue"
    };
    std::array<std::string, 3> type_declaration_keywords {
        "struct", "typedef", "enum"
    };
    std::array<std::string, 3> other_keywords {
        "return", "goto", "sizeof"
    };
    std::array<std::string, 5> arith_operators {
        "+", "-", "*", "/", "%"
    };
    std::array<std::string, 3> logic_operators {
        "!", "&&", "||"
    };
    std::array<std::string, 6> bitwise_operators {
        "&", "|", "^", "~", "<<", ">>"
    };
    std::array<std::string, 2> inc_dec_operators {
        "++", "--"
    };
    std::array<std::string, 5> assign_arithmetic_operators {
        "+=", "-=", "*=", "/=", "%="
    };
    std::array<std::string, 5> assign_bitwise_operators {
        "&=", "|=", "^=", "<<=", ">>="
    };
    std::array<std::string, 2> ternary_operators {
        "?", ":"
    };
    std::array<std::string, 2> struct_operators {
        ".", "->"
    };
    std::array<std::string, 6> comparison_operators {
        "<", ">", "<=", ">=", "==", "!="
    };
    std::array<std::string, 2> scope_brackets {
        "{", "}"
    };
    std::array<std::string, 2> params_brackets {
        "(", ")"
    };
    std::array<std::string, 2> array_brackets {
        "[", "]"
    };
    TokenType _prev_token_type = TokenType::DEL;
    // for () {}
    return result;
}
