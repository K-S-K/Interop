/*==============================================================================
  File: NativeDeviceLib.cpp
  Description: Native device measurement library implementation
  Author: Stanislav Kiselevskii
  Created: 2026.03.09
==============================================================================*/

#include "pch.h"
#include "NativeDeviceLib.h"

#include <thread>
#include <chrono>
#include <random>

namespace
{
    /// <summary>
    /// Simulates work by sleeping for a specified duration with random jitter.
    /// </summary>
    /// <param name="seconds">The base duration in seconds to simulate work.</param>
    void SimulateWork(double seconds)
    {
        static thread_local std::mt19937 rng{ std::random_device{}() };
        std::uniform_real_distribution<double> jitter(-0.5, 0.5);

        // Add jitter to the requested duration
        double actual = seconds + jitter(rng);
        // Ensure minimum duration of 0.1 seconds
        if (actual < 0.1)
            actual = 0.1;

        // Sleep for the calculated duration
        std::this_thread::sleep_for(
            std::chrono::duration<double>(actual));
    }

    /// <summary>
    /// Generates a random double value between 0.0 and 100.0.
    /// </summary>
    /// <returns>A random double value in the range [0.0, 100.0).</returns>
    double GenerateValue()
    {
        static thread_local std::mt19937 rng{ std::random_device{}() };
        std::uniform_real_distribution<double> dist(0.0, 100.0);
        return dist(rng);
    }
}

/// <summary>
/// Performs the first measurement operation.
/// Simulates 3 seconds of work and returns a random measured value.
/// </summary>
/// <returns>A MeasureResult containing the generated value and status.</returns>
MeasureResult __cdecl MeasureOne()
{
    SimulateWork(3.0);

    return MeasureResult{
        GenerateValue(),
        MeasureStatus::Ok
    };
}

/// <summary>
/// Performs the second measurement operation.
/// Simulates 5 seconds of work and returns a random measured value.
/// </summary>
/// <returns>A MeasureResult containing the generated value and status.</returns>
MeasureResult __cdecl MeasureTwo()
{
    SimulateWork(5.0);

    return MeasureResult{
        GenerateValue(),
        MeasureStatus::Ok
    };
}
