using System.Diagnostics;

using ManagedClient.LibWrapper;

namespace ManagedClient;


internal class Program
{
    static async Task Main()
    {
        // Print a welcome message
        Console.WriteLine("Starting measurements...");

        // Start duration measurement
        Stopwatch sw = Stopwatch.StartNew();

        // Prepare tasks
        Task<MeasureResult> t1 = DeviceApi.MeasureOneAsync();
        Task<MeasureResult> t2 = DeviceApi.MeasureTwoAsync();

        // Await both tasks to complete
        MeasureResult[] results = await Task.WhenAll(t1, t2);

        // Stop duration measurement
        sw.Stop();

        // Report common execution duration
        Console.WriteLine($"Completed in {sw.Elapsed.TotalSeconds:F2}s");
        Console.WriteLine();

        // Report returned values and statuses
        Console.WriteLine($"MeasureOne: value={results[0].Value:F2}, status={results[0].Status}");
        Console.WriteLine($"MeasureTwo: value={results[1].Value:F2}, status={results[1].Status}");
    }
}
