cmake_minimum_required(VERSION 3.13)
project(NumClassCpp)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES "NumClassCpp.cpp" "Matrix.cpp" "Dataset.cpp")
set(HEADER_FILES "Matrix.h" "Dataset.h")

add_executable(simple_example ${SOURCE_FILES} ${HEADER_FILES})
