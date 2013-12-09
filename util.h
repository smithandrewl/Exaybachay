#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, const std::string& delimiters);
std::string toLower(const std::string& str);
std::string toAlphaNumeric(const std::string& str);

#endif