cmake_minimum_required(VERSION 2.8.5)

set(CMAKE_C_COMPILER "/opt/intel/bin/icc")
set(CMAKE_CXX_COMPILER "/opt/intel/bin/icpc")
set(CMAKE_BUILD_TYPE Release)

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DREAL_FLOAT")

include_directories(inc)

aux_source_directory(src SOURCE_FILES)

add_library(lsh
  src/BucketHashing.cpp
  src/Geometry.cpp
  src/GlobalVars.cpp
  src/LSH.cpp
  src/LocalitySensitiveHashing.cpp
  src/NearNeighbors.cpp
  src/Random.cpp
  src/SelfTuning.cpp
)
