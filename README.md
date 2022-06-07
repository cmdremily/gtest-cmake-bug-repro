# Steps to Reproduce

Install `git`, `cmake` and add `msbuild.exe` from `C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin\amd64` (or similar) to your `PATH`.

Using `powershell`:

```
git clone https://github.com/cmdremily/gtest-cmake-bug-repro
cd gtest-cmake-bug-repro
mkdir build
cd build
cmake ..
msbuild.exe .\hello_test.vcxproj
```

Actual result:

* CMake succeeds
* Build fails: Cannot open include file: `gmock/gmock.h`.

Expecte result:
* Build succeeds.
