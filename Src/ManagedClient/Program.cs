using System;
using System.Runtime.InteropServices;

namespace ManagedClient;


internal static class NativeMethods
{
    [DllImport(
        "NativeDeviceLib.dll",
        CallingConvention = CallingConvention.Cdecl)]
    public static extern int Sum(int x, int y);
}

internal class Program
{
    static void Main()
    {
        int a = 2;
        int b = 3;

        int result = NativeMethods.Sum(a, b);

        Console.WriteLine($"Sum({a}, {b}) = {result}");
    }
}