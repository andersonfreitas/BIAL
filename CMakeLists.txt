cmake_minimum_required(VERSION 2.8.5)

set(CMAKE_C_COMPILER "/opt/intel/bin/icc")
set(CMAKE_CXX_COMPILER "/opt/intel/bin/icpc")

set (CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(bial-tst)

set(CMAKE_BUILD_TYPE Release)

cmake_policy(SET CMP0042 NEW)

set (CMAKE_POSITION_INDEPENDENT_CODE TRUE)

# include_directories(inc) # não existe
aux_source_directory(src SOURCE_FILES)

find_package( ZLIB REQUIRED )
if ( ZLIB_FOUND )
    include_directories( ${ZLIB_INCLUDE_DIRS} )
endif( ZLIB_FOUND )

# liblsh
# include_directories(../bial/lsh/inc)
# add_subdirectory(../bial/lsh)

# libslic
# include_directories(../bial/slic/inc)
# add_subdirectory(../bial/slic)

# libbial
include_directories(../bial/inc)
add_subdirectory(../bial)

link_libraries(${DEPS_LIBRARIES} -lm)
target_link_libraries(bial-tst libbial liblsh)

# Executables
add_executable(Adjacency-Gray Adjacency-Gray.cpp)
target_link_libraries(Adjacency-Gray libbial)

# add_executable(extract_ts extract_ts.c)
# target_link_libraries(extract_ts tss ${ZLIB_LIBRARIES} libmac6903)
