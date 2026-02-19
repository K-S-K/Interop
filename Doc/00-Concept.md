# Interop Communication Example

## Concept

The document outlines the project's technical requirements and restrictions.

**The example modeling two projects, working together:**

- some device driver (NativeDeviceLib.dll)
- console client application (ManagedClient.exe)

### 1. C ABI, not C++ ABI

Even though the DLL is written in C++, the exported surface must be C-style.

Why:

- C++ name mangling can be compiler-specific
- ABI breaks silently
- You want the DLL to be consumable from any language

### 2. No exceptions across the boundary

Why:

- C++ exceptions must not cross into C#
- C# exceptions must not cross into native

So, errors should be handled via:

- return codes
- or out-parameters

### 3. Managed side uses P/Invoke (DllImport)

Not C++/CLI.

Why:

- C++/CLI is powerful but niche and fragile
- P/Invoke is explicit, testable, and idiomatic
- Better mental model for async layering

## Toolchain & Environment Preparation

**Microsoft Visual Studio** should contain:

- Desktop development with C++
- .NET desktop development
