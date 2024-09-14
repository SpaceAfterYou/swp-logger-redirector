#include "hooks/show_user_ex_log/install.hpp"
#include "hooks/show_user_ex_log/mock.hpp"

namespace lr::hooks::show_user_ex_log
{
	auto install(void) -> bool
	{
		using namespace swpsdk::detour;

#if defined(_X86_)
		const auto signature{ "?ShowUserExLog@CDebugLog@@QAAXPBDZZ" };
#elif defined(_AMD64_)
		const auto signature{ "?ShowUserExLog@CDebugLog@@QEAAXPEBDZZ" };
#endif

		auto ptr{ DetourFindFunction("GamePlugin.vPlugin", signature) };

		if (NULL == ptr) {
			spdlog::critical("{0} not found in GamePlugin.vPlugin", signature);
			return false;
		}

		return attach(ptr, mock, "ShowUserExLog");
	}
}
