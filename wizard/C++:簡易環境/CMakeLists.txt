#/*-------------------------------------------------------------------------
#    Copyright __$auther$__ __$year$__.
#    Use, modification and distribution are subject to the
#    Boost Software License, Version 1.0.  (See accompanying file
#    LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#*///-----------------------------------------------------------------------

cmake_minimum_required(VERSION 3.19.1)
project(__$project_name$__ CXX)

add_executable(${CMAKE_PROJECT_NAME} ./main.cpp)

target_link_options(${CMAKE_PROJECT_NAME} PRIVATE -lpthread)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE -lm)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE -ldl)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -mavx2)
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
