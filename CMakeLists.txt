cmake_minimum_required(VERSION 3.2)
project (smmult VERSION 1.0.0 LANGUAGES CXX)

include_directories(
  "include"
  "src"
)

add_executable(
  smmult
  src/main.cpp
  src/matrix.cpp
)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")    
target_compile_features(smmult PUBLIC cxx_std_17)
