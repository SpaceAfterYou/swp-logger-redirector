#include "plugin.hpp"
#include "hooks/show_log/install.hpp"
#include "hooks/show_user_ex_log/install.hpp"

namespace lr
{
	auto plugin::main(void) const -> int32_t
	{
		using namespace swpsdk::detour;
		using namespace hooks;

		if (not transaction({ show_log::install, show_user_ex_log::install })) {
			return EXIT_FAILURE;
		}

		return EXIT_SUCCESS;
	}
}
