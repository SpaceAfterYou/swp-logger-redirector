// pch.hpp: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here

#include <Windows.h>
#include <detours/detours.h>

#include <swpsdk/plugin/base.hpp>
#include <swpsdk/plugin/attach.hpp>


void logs(void* _this, unsigned int level, char* format, ...);


using CDebugLog_ShowLog_t = void __cdecl(int, char const*, ...);

#endif //PCH_H