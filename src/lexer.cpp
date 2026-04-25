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
    for (index; index < input.size(); index++) {
        switch (input[index]) {
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': 
            case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': 
            case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
            case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': 
            case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': 
            case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z': case '_': 
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':{
                result += input[index];
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

std::string read_num_liter(const std::string& input, tokens_list& output_list, int index) {
    for (index; index < input.size(); index++) {

    }
}

std::string read_str_liter(const std::string& input, int index) {
    std::string result;
    for (index; (index < input.size()) && (input[index] != '"'); index++) {
        result += input[index];
    }
    if (index == input.size()) {
        std::cerr << "Lexer - read_str_literal: \n";
        result = "";
    }
    return result;
}

void lexer_process(const std::string& input, tokens_list output_list) {
    std::unordered_set<std::string> key_words;
    std::unordered_set<std::string> opreators;
    TokenType prev_token_type = TokenType::KEY;
    TokenType curr_token_type = TokenType::KEY;
    std::string token;
    for (u_int32_t i = 0; i < input.size(); i++) {
        switch(input[i]) {
            case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': 
            case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': 
            case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
            case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': 
            case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': 
            case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z': case '_': {
                token = read_identifier(input, i + 1, prev_token_type, key_words);
                i += token.size();
                prev_token_type = TokenType::ID;
                break;
            }
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9': {
                break;
            }
            case '"': {
                break;
            }
            case '\'': {
                break;
            }
            case ' ': case '\t': case '\n': case ';': case ',': 
            case '(': case ')':  case '{':  case '}': {
                curr_token_type = TokenType::DEL;
                output_list.push_back({token, prev_token_type});
                token.clear();
                break;
            }
            default: {
            }
        }
        prev_token_type = curr_token_type;
    }
}
