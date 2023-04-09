#pragma once

#include <swpsdk/plugin/base.hpp>

namespace lr
{
	class plugin final : public swpsdk::plugin::base<plugin>
	{
	public:
		auto main(void) const->int32_t override final;
	};
}
