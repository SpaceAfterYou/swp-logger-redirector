#pragma once

namespace swp_logger_redirector
{
  class plugin final : public swpsdk::plugin::base<plugin>
  {
  public:
    auto main(void) const -> void override;
  };
}
