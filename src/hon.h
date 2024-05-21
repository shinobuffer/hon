#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace hon {

class HonInfo {
public:
  HonInfo(std::string_view name);
  ~HonInfo() = default;

public:
  std::string name() const;

private:
  std::string m_convension;
  std::string m_author;
  std::string m_title;
  std::string m_type;
  std::vector<std::string> m_tags;
};

} // namespace hon
