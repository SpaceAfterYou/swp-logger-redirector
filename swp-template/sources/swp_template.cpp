// local
#include "swp_template.hpp"

namespace swp_template
{
  auto plugin::main(void) const -> void
  {
    spdlog::info("hello, world!");
  }
};
