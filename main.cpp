#include <hon.h>

#include "print.hpp"

int main(int argc, char const* argv[]) {
  hon::HonInfo info{"(FF40)[山含]运动会(Blue Archive)[中国翻译][无修正]"};
  play::println(info.name());
  return 0;
}
