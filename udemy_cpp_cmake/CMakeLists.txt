cmake_minimum_required(VERSION 3.12)

set(PROJECT "CppTemplate")

project("${PROJECT}_Project" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

option(ENABLE_TESTING "Enable Unit Testing." ON)
option(ENABLE_COVERAGE "Enable Code Coverage." OFF)
option(ENABLE_BENCHMARKING "Enable Benchmarking." ON)

set(LIBRARY_NAME    "${PROJECT}_MyLib")
set(LIBRARY_LINALG  "${PROJECT}_LinAlg")
set(LIBRARY_CATCH2  "${PROJECT}_Catch2")
set(MAIN            "${PROJECT}_Executable")
set(TEST_MAIN       "${PROJECT}_unit_tests")
set(COVERAGE_MAIN   "${PROJECT}_Coverage")
set(BENCHMARK_MAIN  "${PROJECT}_Benchmarks")

option(USE_PRINTF "If you want either to use printf (ON) or cout (OFF)" OFF)

configure_file( "${PROJECT_SOURCE_DIR}/include/ProjectConfig.h.in"
                "${PROJECT_BINARY_DIR}/ProjectConfig.h" @ONLY)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(Documentation)

if(ENABLE_TESTING OR ENABLE_COVERAGE)
    include(CTest)
endif()

if(ENABLE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        include(CodeCoverage)
    else()
        message("Coverage only for GNU|Clang")
        set(ENABLE_COVERAGE OFF)
    endif()
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory("external")
add_subdirectory("src")
add_subdirectory("app")

if (ENABLE_TESTING OR ENABLE_COVERAGE)
    enable_testing()
    add_subdirectory("tests")
endif()

if (ENABLE_BENCHMARKING)
    add_subdirectory("benchmarks")
endif ()