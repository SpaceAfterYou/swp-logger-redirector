#include "plugin.hpp"

auto swpsdk::plugin::get_info(info& _info)->void
{
	_info.game_version = swpsdk::version{ 1, 4, 2, 3 };
	_info.plugin_version = swpsdk::version{ 1 };
	_info.instance = &lr::plugin::instance();
}
