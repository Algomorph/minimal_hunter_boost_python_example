# CMake version, module path
cmake_minimum_required (VERSION 3.4)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
option(
    HUNTER_NO_TOOLCHAIN_ID_RECALCULATION
    "No Toolchain-ID recalculation"
    ON
)
include("HunterGate")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.89.tar.gz"
    SHA1 "a370290a8b32987755a36d64807bf8c7f5b61730"
)
#=================================================================
# Project language configuration
project(example LANGUAGES CXX)
#=================================================================
# Compiler options

# Preliminaries for Compiler
# C++11 standard simplifies things in a lot of obvious ways,
# it also allows us to use Eigen in multithreaded code w/o special initialization
set(CMAKE_CXX_STANDARD 11)
#=================================================================

set(PYTHON_VERSION_MAJOR 3)
set(PYTHON_VERSION_MINOR 6)

# Hunter package retrieval/building, package discovery
hunter_add_package(Boost COMPONENTS python)
find_package(PythonInterp 3 REQUIRED QUIET)
find_package(PythonLibs 3 REQUIRED QUIET)
find_package(Boost COMPONENTS python${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR} REQUIRED QUIET)

PYTHON_ADD_MODULE(module module.cpp)
target_include_directories(module PUBLIC ${PYTHON_INCLUDE_DIRS})
target_link_libraries(module Boost::python${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR} ${PYTHON_LIBRARIES})
