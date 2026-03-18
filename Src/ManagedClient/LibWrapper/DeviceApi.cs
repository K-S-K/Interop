namespace ManagedClient.LibWrapper;

/// <summary>
/// Provides asynchronous wrappers around native measurement methods.
/// </summary>
internal static class DeviceApi
{
    /// <summary>
    /// Asynchronously performs the first measurement operation.
    /// </summary>
    /// <returns>A task that represents the asynchronous operation, containing the measurement result.</returns>
    public static Task<MeasureResult> MeasureOneAsync()
    {
        return Task.Run(() => NativeMethods.MeasureOne());
    }

    /// <summary>
    /// Asynchronously performs the second measurement operation.
    /// </summary>
    /// <returns>A task that represents the asynchronous operation, containing the measurement result.</returns>
    public static Task<MeasureResult> MeasureTwoAsync()
    {
        return Task.Run(() => NativeMethods.MeasureTwo());
    }
}
