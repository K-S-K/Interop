using System.Runtime.InteropServices;

namespace ManagedClient.LibWrapper;

/// <summary>
/// Represents the result of a measurement operation, 
/// including the measured value and its status.
/// </summary>
[StructLayout(LayoutKind.Sequential)]
internal struct MeasureResult
{
    /// <summary>
    /// The measured value.
    /// </summary>
    public double Value;

    /// <summary>
    /// The status of the measurement operation.
    /// </summary>
    public MeasureStatus Status;
}
