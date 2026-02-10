#pragma once

#ifdef NATIVEDEVICELIB_EXPORTS
#define NDL_API __declspec(dllexport)
#else
#define NDL_API __declspec(dllimport)
#endif

extern "C"
{
    NDL_API int __cdecl Sum(int x, int y);
}