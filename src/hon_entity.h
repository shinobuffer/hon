#pragma once

#include <filesystem>

#include "hon_info.h"

namespace hon {

class HonEntity {
public:
  explicit HonEntity(std::filesystem::directory_entry e)
      : m_entry(e), m_info(HonInfo::parse(e.path().filename().c_str())){};
  HonEntity(std::filesystem::path path) : HonEntity(std::filesystem::directory_entry(path)) {}
  ~HonEntity() = default;

public:
  std::filesystem::path path() const { return m_entry.path(); }
  std::filesystem::path absolutePath() const { return std::filesystem::absolute(path()); }
  bool exist() const { return m_entry.exists(); };

private:
  std::filesystem::directory_entry m_entry;
  HonInfo m_info;
};

} // namespace hon
