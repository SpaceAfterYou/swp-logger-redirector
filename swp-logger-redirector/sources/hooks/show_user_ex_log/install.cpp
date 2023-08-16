#include "hooks/show_user_ex_log/install.hpp"
#include "hooks/show_user_ex_log/mock.hpp"

namespace lr::hooks::show_user_ex_log
{
	auto install(void) -> bool
	{
		using namespace swpsdk::detour;

		constexpr static const std::array any_of{ /* x32 */ "?ShowUserExLog@CDebugLog@@QAAXPBDZZ", /* x64 */ "?ShowUserExLog@CDebugLog@@QEAAXPEBDZZ" };

		return std::ranges::any_of(any_of, [](const char* _name)
			{
				auto ptr{ DetourFindFunction("GamePlugin.vPlugin", _name) };

				if (NULL == ptr) {
					spdlog::critical("{0} not found in GamePlugin.vPlugin", _name);
					return false;
				}

				return attach(ptr, mock, "ShowUserExLog");
			});
	}
}
