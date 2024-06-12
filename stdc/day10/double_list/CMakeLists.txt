cmake_minimum_required(VERSION 3.0.0)
project(double_list VERSION 0.1.0 LANGUAGES C)

add_executable(double_list double_list.c main.c)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
