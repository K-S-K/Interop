/*==============================================================================
  File: NativeDeviceLib.h
  Description: Native device library header for interop measurements.
  Author: Stanislav Kiselevskii
  Created: 2026.03.09
==============================================================================*/

#pragma once

// Define API export/import macros for DLL visibility
#ifdef NATIVEDEVICELIB_EXPORTS
    #define NDL_API __declspec(dllexport)
#else
    #define NDL_API __declspec(dllimport)
#endif

#include <stdint.h>

// C-style extern block for C calling convention compatibility
extern "C"
{
    // ========================================================================
    // Enum: MeasureStatus
    // 
    // Description: Status enumeration for measurement operations.
    // ========================================================================
    enum class MeasureStatus : int32_t
    {
        Ok = 0,         // Operation completed successfully
        Failed = 1      // Operation failed
    };

    // ========================================================================
    // Struct: MeasureResult
    // 
    // Description: Result structure containing measurement value and status.
    // ========================================================================
    struct MeasureResult
    {
        double value;           // Measured value
        MeasureStatus status;   // Status of the measurement operation
    };

    // ========================================================================
    // Function: MeasureOne
    // 
    // Description: Performs the first measurement operation.
    // Simulates 3 seconds of work and returns a random measured value.
    // Returns: MeasureResult containing the measured value and status.
    // ========================================================================
    NDL_API MeasureResult __cdecl MeasureOne();

    // ========================================================================
    // Function: MeasureTwo
    // 
    // Description: Performs the second measurement operation.
    // Simulates 5 seconds of work and returns a random measured value.
    // Returns: MeasureResult containing the measured value and status.
    // ========================================================================
    NDL_API MeasureResult __cdecl MeasureTwo();
}
