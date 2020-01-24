cmake_minimum_required(VERSION 3.14)
project(cplusplus_template)

set(CMAKE_CXX_STANDARD 11)

add_executable(cplusplus_template main.cpp common.h Container.h typename.h multi_version_min.h partialOrder.h const_use.h)