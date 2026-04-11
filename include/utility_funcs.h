#ifndef UTILITY_FUNCS_H_
#define UTILITY_FUNCS_H_

#include <fstream>
#include <string>
#include <vector>

std::string read(std::ifstream&);

void get_cmd_args(int, char**, std::vector<std::string>&);

#endif // UTILITY_FUNCS_H_
