using System.Runtime.InteropServices;

namespace ManagedClient.LibWrapper;

/// <summary>
/// Provides P/Invoke signatures for native methods in the device library.
/// </summary>
internal static class NativeMethods
{
    /// <summary>
    /// Performs the first measurement operation and returns the result.
    /// </summary>
    /// <returns>The result of the first measurement operation.</returns>
    [DllImport(
    "NativeDeviceLib.dll",
    CallingConvention = CallingConvention.Cdecl)]
    public static extern MeasureResult MeasureOne();

    /// <summary>
    /// Performs the second measurement operation and returns the result.
    /// </summary>
    /// <returns>The result of the second measurement operation.</returns>
    [DllImport(
        "NativeDeviceLib.dll",
        CallingConvention = CallingConvention.Cdecl)]
    public static extern MeasureResult MeasureTwo();
}
