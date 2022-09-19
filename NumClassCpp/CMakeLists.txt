cmake_minimum_required(VERSION 3.13)
project(NumClassCpp)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES "NumClassCpp.cpp" "Matrix.cpp" "Dataset.cpp" "Func.cpp")
set(HEADER_FILES "Matrix.h" "Dataset.h" "Func.h")

add_executable(numclasscpp ${SOURCE_FILES} ${HEADER_FILES})
