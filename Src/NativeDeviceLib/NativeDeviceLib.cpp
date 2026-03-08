#include "pch.h"
#include "NativeDeviceLib.h"

#include <thread>
#include <chrono>
#include <random>

namespace
{
    void SimulateWork(double seconds)
    {
        static thread_local std::mt19937 rng{ std::random_device{}() };
        std::uniform_real_distribution<double> jitter(-0.5, 0.5);

        double actual = seconds + jitter(rng);
        if (actual < 0.1)
            actual = 0.1;

        std::this_thread::sleep_for(
            std::chrono::duration<double>(actual));
    }

    double GenerateValue()
    {
        static thread_local std::mt19937 rng{ std::random_device{}() };
        std::uniform_real_distribution<double> dist(0.0, 100.0);
        return dist(rng);
    }
}

MeasureResult __cdecl MeasureOne()
{
    SimulateWork(3.0);

    return MeasureResult{
        GenerateValue(),
        MeasureStatus::Ok
    };
}

MeasureResult __cdecl MeasureTwo()
{
    SimulateWork(5.0);

    return MeasureResult{
        GenerateValue(),
        MeasureStatus::Ok
    };
}
