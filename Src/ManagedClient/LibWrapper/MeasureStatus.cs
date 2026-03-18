namespace ManagedClient.LibWrapper;

/// <summary>
/// Represents the status of a measurement operation.
/// </summary>
internal enum MeasureStatus : int
{
    /// <summary>
    /// The measurement completed successfully.
    /// </summary>
    Ok = 0,

    /// <summary>
    /// The measurement failed due to an error.
    /// </summary>
    Failed = 1
}
