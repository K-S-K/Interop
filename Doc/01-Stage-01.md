# Interop Communication Example

## Stage 1. "Hello Interop" - Minimal working example

### Description

- C++  dll exporting a simple function, just int Sum(int x, int y){ return x+y; }
- C# console application connects to the dll, call its function, and prints result to the console.

### Goal

- Prove toolchain
- Prove ABI
- Prove calling convention

### Deliverables

- Native DLL exporting Sum
- C# console calling it
- One clean run, debugger attached on both sides

### Project structure

```text
/Interop
│
├── NativeDeviceLib/          (C++ DLL)
│   ├── include/
│   │   └── NativeDeviceLib.h
│   ├── src/
│   │   └── NativeDeviceLib.cpp
│   └── NativeDeviceLib.vcxproj
│
├── ManagedClient/            (C# console app)
│   ├── Program.cs
│   └── ManagedClient.csproj
│
└── InteropPlayground.sln
```

## Development

### 1.1. Create the solution

1. Open Visual Studio 2026
2. Create a new project
3. Choose Blank Solution
4. Name it: "Interop"

### 1.2. Create the native DLL (C++)

#### 1.2.1 Add the project

1. Right-click solution → Add → New Project
2. Choose:
 • C++
 • Dynamic-Link Library (DLL)
3. Name: "NativeDeviceLib"

#### 1.2.2 Set architecture (critical)

1. Build → Configuration Manager
2. For Active solution platform:
 • Choose ARM64
 • If missing → New… → ARM64 (or your architecture)
3. Ensure:
 • NativeDeviceLib → ARM64 (or your architecture)

 **Note:** If this is wrong, interop will compile but fail at runtime.

#### 1.2.3 Project structure (best practice)

Inside NativeDeviceLib, create:

```text
include/
    NativeDeviceLib.h
src/
    NativeDeviceLib.cpp
```

(The auto-generated .cpp can be deleted.)

#### 1.2.4 Header file (NativeDeviceLib.h)

```C++
#pragma once

#ifdef NATIVEDEVICELIB_EXPORTS
#define NDL_API __declspec(dllexport)
#else
#define NDL_API __declspec(dllimport)
#endif

extern "C"
{
    NDL_API int __cdecl Sum(int x, int y);
}
```

**Why this matters**:

- extern "C" → stable ABI (no name mangling)
- __cdecl → explicit calling convention (even if default)
- Export macro → future-proof

#### 1.2.5 Source file (NativeDeviceLib.cpp)

```C++
#include "NativeDeviceLib.h"

int __cdecl Sum(int x, int y)
{
    return x + y;
}
```

### 1.3. Create the managed client (C#)

#### 1.3.1 Add project

1. Right-click solution → Add → New Project
2. Choose:
 • Console App
 • C#
3. Name: "ManagedClient"

#### 1.3.2 Force ARM64 (no Any CPU)

 1. Right-click ManagedClient → Properties
 2. Go to Build
 3. Platform target:
 • ARM64
 4. Uncheck Prefer 32-bit

This avoids silent x64 emulation traps.

### 1.4. P/Invoke boundary

#### 1.4.1 Edit Program.cs

```CS
using System;
using System.Runtime.InteropServices;

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
```

### 1.5. DLL placement (important)

During debugging, Windows must find the DLL.

The easiest way is to copy it manually, or even better, copy it by post-build step script.

### 1.6. Debugging both sides

#### 1.6.1 Set startup project

- Right-click ManagedClient
- Set as Startup Project

#### 1.6.2 Set breakpoints

- In NativeDeviceLib.cpp → inside Sum
- In Program.cs → before the call

### 1.6.3 Run (F5)

Expected behavior:

- C# breakpoint hits
- Step into → native breakpoint hits
- Result printed: **Sum(2, 3) = 5**
