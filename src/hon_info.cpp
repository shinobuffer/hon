#include "hon_info.h"

#include "utils.hpp"

namespace hon {

HonInfo HonInfo::parse(std::string_view name) {
  HonInfo res;
  if (name.empty()) return res;

  size_t p = 0;
  if (auto [found, next_p, str] = utils::parseBracket(name, p); found) {
    p = next_p;
    res.convension = std::move(str);
  }
  if (auto [found, next_p, str] = utils::parseSquareBracket(name, p); found) {
    p = next_p;
    res.author = std::move(str);
  }
  if (size_t next_p = name.find_first_of("[(", p); next_p != std::string_view::npos) {
    res.title = utils::trim(name.substr(p, next_p - p));
    p = next_p;
  }
  if (auto [found, next_p, str] = utils::parseBracket(name, p); found) {
    p = next_p;
    res.type = std::move(str);
  }
  while (1) {
    auto [found, next_p, str] = utils::parseSquareBracket(name, p);
    if (!found) break;
    p = next_p;
    res.tags.push_back(std::move(str));
  }

  return res;
}

std::string HonInfo::name() const {
  std::string res;
  if (convension.size()) res.append(utils::bracketed(convension));
  if (author.size()) res.append(utils::squireBracketed(author));
  if (title.size()) res.append(title);
  if (type.size()) res.append(utils::bracketed(type));
  for (auto const& item : tags) {
    res.append(utils::squireBracketed(item));
  }
  return res;
}

bool HonInfo::isValid() const { return !author.empty() && !title.empty(); }

} // namespace hon
