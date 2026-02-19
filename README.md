# Interop Communication Example

This is an example project which can be used as a boilerplate of development native C++ dll and C# client exe in one Visual Studio solution.

**The example modeling two projects, working together:**

- some device driver (NativeDeviceLib.dll)
- console client application (ManagedClient.exe)

## [Concept](Doc/00-Concept.md)

The document describes technical requirements and restrictions of the project, including:

- Application Binary Interface
- Exceptions processing policy
- Function wrapping at managed side

## Toolchain & Environment Preparation

The development was performed at Microsoft Visual Studio 2026 IDE.

**Visual Studio** should contain following tools:

- Desktop development with C++
- .NET desktop development

The solution was developed and tested on MacOS running on Silicon M3 processor under Parallels virtualization environment with Windows 11 Pro. So target machine can be different at the project configuration for users with different hardware set.

## [Stage 1. Simplest implementation](./01-Stage-01.md)

At Stage 1 the initial solution creation process is described. The solution contains two projects:

- The simplest c++ library with one function which accepts two parameters and returns sum of them to the client.
- The simplest C# console app which connects to the library, calls the function and prints result to the console.
