#include "hooks/show_log/install.hpp"
#include "hooks/show_log/mock.hpp"

#include <ranges>

namespace lr::hooks::show_log
{
	auto install(void) -> bool
	{
		using namespace swpsdk::detour;

		constexpr static const std::array any_of{ /* x32 */ "?ShowLog@CDebugLog@@QAAXKPBDZZ", /* x64 */ "?ShowLog@CDebugLog@@QEAAXKPEBDZZ" };

		return std::ranges::any_of(any_of, [](const char* _name) 
			{
				auto ptr{ DetourFindFunction("GamePlugin.vPlugin", _name) };

				if (NULL == ptr) {
					spdlog::critical("{0} not found in GamePlugin.vPlugin", _name);
					return false;
				}

				return attach(ptr, mock, "ShowLog");
			});
	}
}
