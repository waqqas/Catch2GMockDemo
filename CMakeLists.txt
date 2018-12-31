cmake_minimum_required(VERSION 3.10)
project(demo)

set(CMAKE_CXX_STANDARD 17)

include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories("${CMAKE_SOURCE_DIR}/tests")        # for GMockCatchListener.h

set(VENDOR_SOURCE_DIR "${CMAKE_SOURCE_DIR}/vendor")

include_directories("${VENDOR_SOURCE_DIR}/Catch2/include")

## google test/mock configuration
add_subdirectory("${VENDOR_SOURCE_DIR}/googletest")
include_directories("${VENDOR_SOURCE_DIR}/googletest/googletest/include")
include_directories("${VENDOR_SOURCE_DIR}/googletest/googlemock/include")

file(GLOB sources src/*.cpp src/*.h tests/*.cpp)
add_executable(demo ${sources})
target_link_libraries(demo gtest gmock)
