My Build flow with multi generators:

```dos
set BUILD_TYPE_VS=Visual Studio 15 2017 Win64
mkdir build
cd build
cmake -G "%BUILD_TYPE_VS%"  ..
cmake --build . --clean-first --config RelWithDebInfo
```

and with single but this works properly if with `cmake_find_package` generator in conan:

```dos
set BUILD_TYPE_NINJA=Ninja
mkdir build
cd build
cmake -G "%BUILD_TYPE_NINJA%"  -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build . --clean-first 
```
