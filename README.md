### cpp-drils
- 写経のためのリポジトリ

- ひな形
  - 構成
    ```
    cpp-drills/
    ├─ CMakeLists.txt
    ├─ CMakePresets.json
    └─ src/
       ├─ day01_erase_remove.cpp
       └─ day02_sort_lambda.cpp
    ```
  - パッケージインストール
    ```
    sudo apt update
    sudo apt install -y build-essential cmake ninja-build gdb clang pkg-config libfmt-dev
    ```
  - `CMakeLists.txt`
    ```
    cmake_minimum_required(VERSION 3.16)
    project(cpp_drills LANGUAGES CXX)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

    add_library(warnings INTERFACE)
    target_compile_options(warnings INTERFACE -Wall -Wextra -Wpedantic)

    file(GLOB SRC_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
    foreach(f ${SRC_LIST})
      get_filename_component(name "${f}" NAME_WE)
      add_executable(${name} "${f}")
      target_link_libraries(${name} PRIVATE warnings)
      find_package(fmt QUIET)
      if(fmt_FOUND)
        target_link_libraries(${name} PRIVATE fmt::fmt)
        target_compile_definitions(${name} PRIVATE HAS_FMT=1)
      endif()
    endforeach()
    ```
  - `CMakePresets.json`
    ```
    {
      "version": 3,
      "cmakeMinimumRequired": {"major": 3, "minor": 16},
      "configurePresets": [
        {"name": "debug",   "generator": "Ninja", "binaryDir": "${sourceDir}/build/debug",
         "cacheVariables": {"CMAKE_BUILD_TYPE":"Debug"}},
        {"name": "release", "generator": "Ninja", "binaryDir": "${sourceDir}/build/release",
         "cacheVariables": {"CMAKE_BUILD_TYPE":"Release"}}
      ],
      "buildPresets": [
        {"name":"b-debug",   "configurePreset":"debug"},
        {"name":"b-release", "configurePreset":"release"}
      ],
      "testPresets": []
    }
    ```
