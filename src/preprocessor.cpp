#include "preprocessor.h"

#include <iostream>
#include <regex>
#include <sstream>
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
    std::regex line_comm_expr("//[^\n]*(\n|$)");
    std::regex block_comm_expr("/\\*([^*]|\\*+[^*/])*\\*+/");
    result = std::regex_replace(result, line_comm_expr, "$1");
    result = std::regex_replace(result, block_comm_expr, "");
    return result;
}

std::string no_directives(const std::string& input) {
    std::string result = input;
    std::regex dir_expr("#[a-zA-Z]*[^\n]*(\n)+");
    result = std::regex_replace(result, dir_expr, "");
    return result;
}

std::string preprocessed(const std::string& input) {
    std::string result;
    std::string open_com_sym  = "/*";
    std::string close_com_sym = "*/";
    u_int32_t ocs_counter = 0;
    u_int32_t ccs_counter = 0;
    int32_t stray_ocs_line = -1;
    int32_t stray_ccs_line = -1;
    u_int32_t EOL_counter = 1;
    for (u_int32_t i = 1; i < input.size(); i++) {
        if (input[i] == '\n') { EOL_counter++; }
        if (input.substr(i - 1, 2) == open_com_sym) {
            stray_ocs_line = EOL_counter;
            stray_ccs_line = -1;
            ocs_counter++;
        }
        else if (input.substr(i - 1, 2) == close_com_sym) {
            stray_ocs_line = -1;
            stray_ccs_line = EOL_counter;
            ccs_counter++;
        }
    }
    if (stray_ocs_line == -1) {
        if (ocs_counter == ccs_counter) {
            result = no_empty_symbols(no_comments(no_directives(input)));
        }
        else {
            std::cout << "Preprocessor: Stray end of multi-line comment occured at line " << stray_ccs_line << ".\n";
        }
    }
    else {
        std::cout << "Preprocessor: Stray beginning of multi-line comment occured at line " << stray_ocs_line << ".\n";
    }
    return result;
}
