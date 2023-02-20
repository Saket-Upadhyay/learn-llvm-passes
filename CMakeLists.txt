project(learn-llvm-passes)

# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.7)

# Required packages
find_package(PkgConfig REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_DIR}")

# compiler must be 17
set(CMAKE_CXX_STANDARD 17)

# compile with debug flags
set(CMAKE_BUILD_TYPE Debug)


if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(LLVM 14.0 REQUIRED CONFIG)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    find_package(LLVM 14.0 REQUIRED CONFIG)
else()
    message(FATAL_ERROR "${CMAKE_SYSTEM_NAME} is not supported yet")
endif ()

# LLVM_RTTI Configuration
if (NOT LLVM_ENABLE_RTTI)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif ()

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

message("LLVM STATUS:
  Definitions ${LLVM_DEFINITIONS}
  Includes    ${LLVM_INCLUDE_DIRS}
  Libraries   ${LLVM_LIBRARY_DIRS}"
        )

include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
add_definitions(${LLVM_DEFINITIONS})

#Add Cluster
add_subdirectory(source)