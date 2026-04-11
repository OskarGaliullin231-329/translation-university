#include "../include/preprocessor.h"

#include <regex>
#include <string>

std::string no_empty_symbols(const std::string& input) {
    std::string result;
    std::stringstream ss(input);
    std::string token;
    while (ss >> token) { result += token + ' '; }
    if (result[result.size() - 1] == ' ') { result.pop_back(); }
    return result;
}

std::string no_comments(const std::string& input) {
    std::string result = input;
    std::regex line_comm_expr("//[a-zA-z_0-9 \t/\\!@#$%^&\\*\\(\\)\\[\\]{}\"'<>]*\n");
    std::regex block_comm_expr("/\\*[a-zA-z_0-9 \t/\\!@#$%^&\\*\\(\\)\\[\\]{}\"'<>\n]*\\*/");
    result = std::regex_replace(result, line_comm_expr, "");
    result = std::regex_replace(result, block_comm_expr, "");
    return result;
}

std::string preprocessed(const std::string& input) {
    std::string result = no_empty_symbols(no_comments(input));
    return result;
}
