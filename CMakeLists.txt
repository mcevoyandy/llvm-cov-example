# Require a minimum version of 3.28 to ensure c++20 features are available
cmake_minimum_required(VERSION 3.28)

project(llvm-cov-mwe)

set(CMAKE_CXX_STANDARD 20)  # Set C++ 20 as the standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Don't allow "decaying" to a lower standard

# Check compiler and exit if not Clang > 18.0
message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(FATAL_ERROR "This project targets Clang but you are using ${CMAKE_CXX_COMPILER_ID}")
endif()
if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 18.0)
    message(FATAL_ERROR "This project requires Clang 18.0 or later")
endif()

# Add options for the user to set
option(BUILD_UNIT_TESTS "Build unit tests." OFF)
option(COVERAGE "Run code coverage." OFF)

# Fetch the Google Test library
# NOTE: This points to the latest release and should be checked periodically.
if(BUILD_UNIT_TESTS)
    # Set flags for code coverage. NOTE: This will set it for EVERYTHING in the project. See per-target option below.
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")

    # Use Google Test
    include(FetchContent)
    fetchcontent_declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
    )
    fetchcontent_makeavailable(googletest)
    enable_testing()
    include(GoogleTest)
endif()

# Do all the other CMake stuff you'd do in a normal project
add_library(cool_stuff src/cool_stuff.cpp)
target_include_directories(cool_stuff PUBLIC include)
if (COVERAGE)
    # If you set as global, gtest and anything else compiled in this project will also have coverage flags
    target_compile_options(cool_stuff PRIVATE -fprofile-instr-generate -fcoverage-mapping -fcoverage-mcdc)
    target_link_options(cool_stuff PRIVATE -fprofile-instr-generate -fcoverage-mcdc)
endif()

add_library(other_stuff src/other_stuff.cpp)
target_include_directories(other_stuff PUBLIC include)
if (COVERAGE)
    # If you set as global, gtest and anything else compiled in this project will also have coverage flags
    target_compile_options(other_stuff PRIVATE -fprofile-instr-generate -fcoverage-mapping -fcoverage-mcdc)
    target_link_options(other_stuff PRIVATE -fprofile-instr-generate -fcoverage-mcdc)
endif()

if(BUILD_UNIT_TESTS)
    add_executable(
        cool_stuff_unit_tests test/cool_stuff_unit_tests.cpp
    )
    target_include_directories(cool_stuff_unit_tests PRIVATE include)
    target_link_libraries(cool_stuff_unit_tests
      GTest::gtest_main
      cool_stuff
    )

    add_executable(
        other_stuff_unit_tests test/other_stuff_unit_tests.cpp
    )
    target_include_directories(other_stuff_unit_tests PRIVATE include)
    target_link_libraries(other_stuff_unit_tests
      GTest::gtest_main
      other_stuff
    )

    if (COVERAGE)
        # If you set as global, gtest and anything else compiled in this project will also have coverage flags
        target_compile_options(cool_stuff_unit_tests PRIVATE -fprofile-instr-generate -fcoverage-mapping -fcoverage-mcdc)
        target_link_options(cool_stuff_unit_tests PRIVATE -fprofile-instr-generate -fcoverage-mcdc)

        target_compile_options(other_stuff_unit_tests PRIVATE -fprofile-instr-generate -fcoverage-mapping -fcoverage-mcdc)
        target_link_options(other_stuff_unit_tests PRIVATE -fprofile-instr-generate -fcoverage-mcdc)

        # NOTE: This command is only tied to one of our executables and will not run if it is already built.
        message(STATUS "Generating coverage reports")
        add_custom_command(TARGET cool_stuff_unit_tests
            POST_BUILD
            COMMAND /bin/bash "${PROJECT_SOURCE_DIR}/scripts/make_coverage_reports.sh" "${CMAKE_BINARY_DIR}"
        )
    endif()

    gtest_discover_tests(cool_stuff_unit_tests WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
    gtest_discover_tests(other_stuff_unit_tests WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif()
