using System;
using ManagedClient.LibWrapper;

namespace ManagedClient;


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
