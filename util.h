#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>
#include <boost/functional/hash.hpp>

std::vector<std::string> split(const std::string& str, const std::string& delimiters);
std::string              toLower(const std::string& str);
std::string              toAlphaNumeric(const std::string& str);

// Custom hash function for std::pairs
// Source: stack overflow (http://stackoverflow.com/questions/7222143/unordered-map-hash-function-c)
// Author: Kerrek SB
namespace std {
  template<typename S, typename T> struct hash<pair<S, T>> {
    inline size_t operator()(const pair<S, T> & v) const {
      size_t seed = 0;
      boost::hash_combine(seed, v.first);
      boost::hash_combine(seed, v.second);
      return seed;
    }
  };
}

#endif