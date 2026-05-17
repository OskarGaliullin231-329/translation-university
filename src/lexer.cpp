#include "lexer.h"

#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <unordered_set>

#include "utility_funcs.h"

typedef std::list<std::pair<std::string, TokenType>> tokens_list;

std::string read_identifier(const std::string& input, int index, TokenType& tt, std::unordered_set<std::string>& key_words) {
    std::string result;
    for (std::size_t i = index; i < input.size(); i++) {
        switch (input[i]) {
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': 
            case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': 
            case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
            case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': 
            case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': 
            case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z': case '_': 
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':{
                result += input[i];
                break;
            }
            default: {
                goto end;
            }
        }
    }
    end:
    tt = TokenType::ID;
    if (key_words.find(result) != key_words.end()) {
        tt = TokenType::KEY;
    }
    return result;
}

std::string read_num_liter(const std::string& input, int index) {
    std::string result;
    int dot_count = 0;
    for (std::size_t i = index; i < input.size(); i++) {
        switch (input[i]) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9': {
                result += input[i];
                break;
            }
            case '.': {
                dot_count++;
                if (dot_count > 1) { 
                    std::cerr << "Lexer - read_num_liter: too much dots occured in number-literal.\n";
                    return "";
                }
                result += input[i];
                break;
            }
            case ' ': case '\t': case '\n': case ';': case ',': 
            case '(': case ')':  case '{':  case '}': {
                goto end;
            }
            default: {
                std::cerr << "Lexer - read_num_liter: unexpected symbol occured in number-literal - '" << input[i] << "'.\n";
                return "";
            }
        }
    }
    end:
    return result;
}

std::string read_str_liter(const std::string& input, int index) {
    std::string result;
    std::size_t i;
    for (i = index; i < input.size(); i++) {
        if (input[i] != '"') {
            result += input[i];
        }
        else {
            break;
        }
    }
    if (input.size() == i) {
        std::cerr << "Lexer - read_str_literal: Unclosed qoutes occured.\n";
        result = "";
    }
    return result;
}

std::string read_ch_liter(const std::string& input, int index) {
    std::string result;
    std::size_t i;
    for (i = index; i < input.size(); i++) {
        if (input[i] != '"') {
            result += input[i];
        }
        else {
            break;
        }
    }
    if (result.size() == 0) {
        std::cerr << "Lexer - read_ch_literal: Empty character literal occured.\n";
    }
    else if (result.size() > 1) {
        std::cerr << "Lexer - read_ch_literal: Too much symbols in character literal.\n";
        result = "";
    }
    if (input.size() == i) {
        std::cerr << "Lexer - read_ch_literal: Unclosed qoutes occured.\n";
        result = "";
    }
    return result;
}

std::string read_operator(const std::string& input, int index, const std::unordered_set<std::string>& operators) {
    std::string result{input[index]};
    // std::cout << result << " -> ";
    while (operators.find(result) != operators.end()) {
        index++;
        result += input[index];
    }
    result.pop_back();
    // std::cout << result << '\n';
    return result;
}

void lexer_process(const std::string& input, std::list<std::pair<std::string, TokenType>>& output_list) {
    std::unordered_set<std::string> key_words {
        // types
        "void",
        "int",
        "float",
        "double",
        "char",
        // type specifiers
        "long",
        "short",
        "signed",
        "unsigned",
        // variable specifiers
        "const",
        "static",
        "volatile",
        "extern",
        "register",
        // type wrapers
        "union",
        "auto",
        // switch-case
        "switch",
        "case",
        "default",
        // conditions
        "if",
        "else",
        // loops
        "for",
        "while",
        "do",
        // loop management
        "break",
        "continue",
        // type declaration
        "struct",
        "typedef",
        "enum",
        // other
        "return",
        "goto",
        "sizeof"
    };
    std::unordered_set<std::string> operators {
        "+", "-", "*", "/", "%",           // arithmetic
        "!", "&&", "||",                   // logical
        "&", "|", "^", "~", "<<", ">>",    // bitwise logical
        "++", "--",                        // inc & dec
        "=", "+=", "-=", "*=", "/=", "%=", // assignment arithmetic
        "&=", "|=", "^=", "<<=", ">>="     // assignment bitwise logical
        "?", ":",                          // ternary
        ".", "->",                         // struct
        "<", ">", "<=", ">=", "==", "!="   // comparison
    };
    TokenType token_type = TokenType::KEY;
    std::string token;
    for (std::size_t i = 0; i < input.size(); i++) {
        switch(input[i]) {
            // identifier and key word handler
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': 
            case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': 
            case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
            case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': 
            case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': 
            case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z': case '_': {
                token = read_identifier(input, i, token_type, key_words);
                i += token.size() - 1;
                break;
            }
            // number literals handler
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9': {
                token = read_num_liter(input, i);
                i += token.size() - 1;
                token_type = TokenType::LIT;
                break;
            }
            // string literals handler
            case '"': {
                token = read_str_liter(input, i + 1);
                if (!token.empty()) {
                    token = "\"" + token + "\"";
                }
                i += token.size() - 1;
                token_type = TokenType::LIT;
                break;
            }
            // character literal handler
            case '\'': {
                token = "'" + read_ch_liter(input, i + 1) + "'";
                i += token.size() - 1;
                token_type = TokenType::LIT;
                break;
            }
            // delimiter handler
            case ' ': case '\t': case '\n': case ';': case ',': 
            case '(': case ')':  case '{':  case '}': case '[': case ']': {                
                token.clear();
                token += input[i];
                token_type = TokenType::DEL;
                break;
            }
            // operator handler
            case '+': case '-': case '*': case '/': case '%':
            case '&': case '|': case '!': case '~': case '^': 
            case '=': case '<': case '>': case '?': case ':': 
            case '.': {
                token = read_operator(input, i, operators);
                i += token.size() - 1;
                token_type = TokenType::OP;
                break;
            }
            // exception handler
            default: {
                std::cout << "Lexer: Hmm... What interesting symbols I got here... NOM NOM NOM!\n";
                std::cout << "\"And since then Lexer had never wanted anymore typical symbols. What a gourmet.\"\n";
                std::cout << "Cursed sym: " << input[i] << '\n';
            }
        }
        if (!token.empty()) {
            output_list.push_back({token, token_type});
        }
        else {
            std::cerr << "Lexer fell...\n";
            output_list.clear();
            return;
        }
        token.clear();
    }
}
