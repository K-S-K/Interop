using System.Runtime.InteropServices;

namespace ManagedClient.LibWrapper;

/// <summary>
/// Provides P/Invoke signatures for native methods in the device library.
/// </summary>
internal static class NativeMethods
{
    /// <summary>
    /// Sums two integers and returns the result.
    /// </summary>
    /// <param name="x">The first integer.</param>
    /// <param name="y">The second integer.</param>
    /// <returns>The sum of the two integers.</returns>
    [DllImport(
        "NativeDeviceLib.dll",
        CallingConvention = CallingConvention.Cdecl)]
    public static extern int Sum(int x, int y);
}
