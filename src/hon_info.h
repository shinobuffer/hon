#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace hon {

struct HonInfo {
  static HonInfo parse(std::string_view name);

  std::string name() const;
  bool isValid() const;

  std::string convension;
  std::string author;
  std::string title;
  std::string type;
  std::vector<std::string> tags;
};

} // namespace hon
