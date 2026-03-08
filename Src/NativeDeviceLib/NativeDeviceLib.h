#pragma once

#ifdef NATIVEDEVICELIB_EXPORTS
#define NDL_API __declspec(dllexport)
#else
#define NDL_API __declspec(dllimport)
#endif

#include <stdint.h>

extern "C"
{
    enum class MeasureStatus : int32_t
    {
        Ok = 0,
        Failed = 1
    };

    struct MeasureResult
    {
        double value;
        MeasureStatus status;
    };

    NDL_API MeasureResult __cdecl MeasureOne();
    NDL_API MeasureResult __cdecl MeasureTwo(); 
}
