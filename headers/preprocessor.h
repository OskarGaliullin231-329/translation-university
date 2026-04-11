#ifndef PREPROCESSOR_H_
#define PREPROCESSOR_H_

#include <fstream>
#include <regex>
#include <string>
#include <list>

std::string no_empty_symbols(const std::string&);

std::string no_comments(const std::string&);

std::string preprocessed(const std::string&);

#endif // PREPROCESSOR_H_
