#include <filesystem>
#include <iostream>

#include <cxxopts.hpp>
#include <debug.hpp>

#include <hon_entity.h>

int main(int argc, char const* argv[]) {
  cxxopts::Options options("hon", "WIP");
  // clang-format off
  options.add_options()
    ("i,info", "Parse Hon's info", cxxopts::value<std::string>())
    ("r,recursive", "Perform operation on directory recursively")
    ("v,verbose", "Show operation's detail")
    ("h,help", "Show usage");
  // clang-format on
  options.allow_unrecognised_options();
  auto args = options.parse(argc, argv);

  if (args.count("help")) {
    std::cout << options.help();
    return 0;
  }

  // TODO
  if (auto arg = args.as_optional<std::string>("info"); arg) {
    auto filename = std::filesystem::path(arg.value()).filename();
    debug(), "--info", filename;
    return 0;
  }

  return 0;
}
