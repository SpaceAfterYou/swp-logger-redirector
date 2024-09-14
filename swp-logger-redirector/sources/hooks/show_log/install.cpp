#include "hooks/show_log/install.hpp"
#include "hooks/show_log/mock.hpp"

#include <ranges>

namespace lr::hooks::show_log
{
	auto install(void) -> bool
	{
		using namespace swpsdk::detour;

#if defined(_X86_)
		const auto signature{ "?ShowLog@CDebugLog@@QAAXKPBDZZ" };
#elif defined(_AMD64_)
		const auto signature{ "?ShowLog@CDebugLog@@QEAAXKPEBDZZ" };
#endif

		auto ptr{ DetourFindFunction("GamePlugin.vPlugin", signature) };

		if (NULL == ptr) {
			spdlog::critical("{0} not found in GamePlugin.vPlugin", signature);
			return false;
		}

		return attach(ptr, mock, "ShowLog");
	}
}
