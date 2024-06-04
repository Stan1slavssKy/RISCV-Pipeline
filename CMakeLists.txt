cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(RISCV-PIPELINE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(RISCV_PIPELINE_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(RISCV_PIPELINE_BINARY_ROOT ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Werror -Wshadow")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -fno-exceptions")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# --------------------------clang-format--------------------------------------

file(GLOB_RECURSE ALL_SOURCES_FILES *.cpp *.h)

find_program(CLANG_FORMAT_EXECUTABLE NAMES clang-format)

add_custom_target(clang-force-format
    COMMAND ${CLANG_FORMAT_EXECUTABLE}
    -i
    -style=file
    --verbose
    ${ALL_SOURCES_FILES}
)

set(SOURCES
    components/data_memory.cpp
    components/insn_memory.cpp
    components/regfile.cpp
)
add_library(simulator_static STATIC ${SOURCES})
target_include_directories(simulator_static PUBLIC ${RISCV_PIPELINE_ROOT})

add_executable(simulator simulator.cpp)
add_dependencies(simulator simulator_static)
target_link_libraries(simulator PUBLIC simulator_static)
