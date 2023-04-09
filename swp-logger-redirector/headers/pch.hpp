// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// #define SPDLOG_WCHAR_TO_UTF8_SUPPORT
#define SPDLOG_USE_STD_FORMAT

// add headers that you want to pre-compile here
#include "framework.hpp"

#include <swpsdk/plugin/base.hpp>
#include <swpsdk/plugin/info.hpp>
#include <swpsdk/plugin/get_info.hpp>
#include <swpsdk/extensions/spdlog/system_error.hpp>

#include <swpsdk/detour/transaction.hpp>
#include <swpsdk/detour/attach.hpp>

#include <detours/detours.h>
#include <spdlog/spdlog.h>

#include <filesystem>
#include <fstream>
#include <string>

#endif //PCH_H
