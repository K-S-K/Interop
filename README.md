# Interop Communication Example

This is an example project that can serve as a boilerplate for developing a native C++ DLL and a C# client EXE in a single Visual Studio solution.

**The example modeling two projects, working together:**

- some device driver (NativeDeviceLib.dll)
- console client application (ManagedClient.exe)

## [Concept](Doc/00-Concept.md)

The document describes technical requirements and restrictions of the project, including:

- Application Binary Interface
- Exceptions processing policy
- Function wrapping at the managed side

## Toolchain & Environment Preparation

The development was performed in Microsoft Visual Studio 2026.

**Visual Studio** should contain the following tools:

- Desktop development with C++
- .NET desktop development

The solution was developed and tested on macOS running on a Silicon M3 processor under Parallels virtualization environment with Windows 11 Pro. So the target machine can be different at the project configuration for users with different hardware sets.

## [Stage 1. Simplest implementation](Doc/01-Stage-01.md)

At Stage 1, the initial solution creation process is described. The solution contains two projects:

- The simplest C++ library with one function that accepts two parameters and returns the sum of them to the client.
- The simplest C# console app which connects to the library, calls the function, and prints the result to the console.
