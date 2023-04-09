#include "hooks/show_log/install.hpp"
#include "hooks/show_log/mock.hpp"

namespace lr::hooks::show_log
{
	auto install(void) -> bool
	{
		using namespace swpsdk::detour;

		static auto ptr{ DetourFindFunction("GamePlugin.vPlugin", "?ShowLog@CDebugLog@@QAAXKPBDZZ") };

		if (NULL == ptr) {
			spdlog::critical("?ShowLog@CDebugLog@@QAAXKPBDZZ not found in GamePlugin.vPlugin");
			return false;
		}

		return attach(ptr, mock, "ShowLog");
	}
}
