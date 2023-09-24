cmake_minimum_required(VERSION 3.0.0)
project(AsadHome VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(AsadHome my_password.h my_password.cpp main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
