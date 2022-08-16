// local
#include "swp_logger_redirector.hpp"

auto swpsdk::plugin::attach(void) -> swpsdk::plugin::info*
{
	return new swpsdk::plugin::info
	{
		.game_version = version{1, 4, 2, 3},
		.plugin_version = version{1},
		.instance = &swp_logger_redirector::plugin::instance()
	};
}
