#include "hon.h"

namespace hon {

static std::string bracketed(std::string_view str) {
  std::string res;
  res.reserve(str.size() + 2);
  return res.append("(").append(str).append(")");
}

static std::string squire_bracketed(std::string_view str) {
  std::string res;
  res.reserve(str.size() + 2);
  return res.append("[").append(str).append("]");
}

HonInfo::HonInfo(std::string_view name) {
  if (name.empty()) return;

  std::size_t p = 0;
  // convention
  if (name[p++] == '(') {
    if (std::size_t i = name.find(')', p); i != std::string_view::npos) {
      m_convension = name.substr(p, i - p);
      p = ++i;
    }
  }
  // author
  if (name[p++] == '[') {
    if (std::size_t i = name.find(']', p); i != std::string_view::npos) {
      m_author = name.substr(p, i - p);
      p = ++i;
    }
  }
  // title

  // type
  if (name[p]) {
  }

  // tags
}

std::string HonInfo::name() const {
  std::string res;
  if (m_convension.size()) res.append(bracketed(m_convension));
  if (m_author.size()) res.append(squire_bracketed(m_author));
  if (m_title.size()) res.append(m_title);
  if (m_type.size()) res.append(bracketed(m_type));
  for (auto& item : m_tags) {
    res.append(bracketed(item));
  }
  return res;
}

} // namespace hon
