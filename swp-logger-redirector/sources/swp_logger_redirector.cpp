// local
#include "swp_logger_redirector.hpp"

namespace swp_logger_redirector
{
	auto plugin::main(void) const -> void
	{
		auto lib = LoadLibrary(TEXT("GamePlugin.vPlugin"));
		if (NULL == lib) {
			spdlog::error("GamePlugin.vPlugin not loaded");
			return;
		}

		auto func = reinterpret_cast<CDebugLog_ShowLog_t*>(GetProcAddress(lib, "?ShowLog@CDebugLog@@QAAXKPBDZZ"));
		if (NULL == func) {
			spdlog::error("Method CDebugLog::ShowLog not found");
			return;
		}

		if (NO_ERROR  != DetourTransactionBegin()) {
			spdlog::error("DetourTransactionBegin fail");
			return;
		}

		if (NO_ERROR != DetourUpdateThread(GetCurrentThread())) {
			spdlog::error("DetourUpdateThread fail");
			return;
		}

		if (NO_ERROR != DetourAttach(&(PVOID&)func, logs)) {
			spdlog::error("DetourAttach fail");
			return;
		}

		if (NO_ERROR != DetourTransactionCommit()) {
			spdlog::error("DetourTransactionCommit fail");
			return;
		}
	}
};
