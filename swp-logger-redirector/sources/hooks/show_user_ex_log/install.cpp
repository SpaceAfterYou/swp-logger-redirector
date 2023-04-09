#include "hooks/show_user_ex_log/install.hpp"
#include "hooks/show_user_ex_log/mock.hpp"

namespace lr::hooks::show_user_ex_log
{
	auto install(void) -> bool
	{
		using namespace swpsdk::detour;

		static auto ptr{ DetourFindFunction("GamePlugin.vPlugin", "?ShowUserExLog@CDebugLog@@QAAXPBDZZ") };

		if (NULL == ptr) {
			spdlog::critical("?ShowUserExLog@CDebugLog@@QAAXPBDZZ not found in GamePlugin.vPlugin");
			return false;
		}

		return attach(ptr, mock, "ShowUserExLog");
	}
}
