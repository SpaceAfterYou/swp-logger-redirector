#include "hooks/show_user_ex_log/mock.hpp"

namespace lr::hooks::show_user_ex_log
{
	void mock(void* _this, const char* format, ...)
	{
		if (nullptr == format) {
			spdlog::warn("[ShowUserExLog] received null format");
			return;
		}

		va_list args;
		va_start(args, format);

		char buffer[4096]{};
		vsprintf_s(buffer, sizeof(buffer), format, args);

		spdlog::info("[ShowUserExLog]: {}", buffer);
	}
}
