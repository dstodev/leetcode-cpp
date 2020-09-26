cmake_minimum_required(VERSION 3.15)

project(CppKata)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

add_subdirectory(third-party)
add_subdirectory(kata)
