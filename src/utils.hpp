#pragma once

#include <cctype>
#include <string>
#include <string_view>

namespace hon::utils {

struct ParseBracketResult {
  bool found;
  size_t next_pos;
  std::string str;
};

inline ParseBracketResult parseBracket(std::string_view str, size_t pos, char lb = '(', char rb = ')') {
  // if (pos >= str.size()) return {.found = false};
  size_t p = str.find_first_not_of(" \t", pos);
  if (p == std::string_view::npos || str[p++] != lb) return {.found = false};
  size_t p_head = p;
  while (p < str.size()) {
    if (str[p++] == rb) return {.found = true, .next_pos = p, .str = std::string(str.substr(p_head, p - p_head - 1))};
  }
  return {.found = false};
}

inline ParseBracketResult parseSquareBracket(std::string_view str, size_t pos) {
  return parseBracket(str, pos, '[', ']');
}

inline std::string bracketed(std::string_view str, char lb = '(', char rb = ')') {
  std::string res;
  res.reserve(str.size() + 2);
  res.push_back(lb);
  res.append(str);
  res.push_back(rb);
  return res;
}

inline std::string squireBracketed(std::string_view str) { return bracketed(str, '[', ']'); }

inline std::string& trim(std::string& str) {
  if (str.empty()) return str;
  str.erase(0, str.find_first_not_of(" \t"));
  str.erase(str.find_last_not_of(" \t") + 1);
  return str;
}

inline std::string_view trim(std::string_view str) {
  std::string_view res(str);
  if (res.empty()) return res;

  size_t p = res.find_first_not_of(" \t");
  res.remove_prefix(p == std::string_view::npos ? res.size() : p);
  p = res.find_last_not_of(" \t");
  res.remove_suffix(p == std::string_view::npos ? res.size() : res.size() - 1 - p);
  return res;
}

} // namespace hon::utils
