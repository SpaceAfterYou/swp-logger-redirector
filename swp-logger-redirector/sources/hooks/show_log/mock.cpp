#include "hooks/show_log/mock.hpp"

namespace lr::hooks::show_log
{
	void mock(void* _this, unsigned int level, const char* format, ...)
	{
		if (nullptr == format) {
			spdlog::warn("[ShowLog] [{}] received null format", level);
			return;
		}

		va_list args;
		va_start(args, format);

		char buffer[4096]{};
		vsprintf_s(buffer, sizeof(buffer), format, args);

		spdlog::info("[ShowLog] [{}]: {}", level, buffer);
	}
}
