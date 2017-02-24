# cmake -DCMAKE_BUILD_TYPE=Debug ..
# cmake -DCMAKE_BUILD_TYPE=Release ..
cmake_minimum_required(VERSION 2.8)
project(androidjni)

# Compiler warning and optimization flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# androidjni Library
file(GLOB ANDJNI_SOURCES
  jutils/*.cpp
  src/*.cpp
)
include_directories(BEFORE ${PROJECT_SOURCE_DIR}/jutils)
add_library(androidjni STATIC ${ANDJNI_SOURCES})
install (TARGETS androidjni ARCHIVE DESTINATION lib)
file(GLOB_RECURSE header_files "*.h" "*.hpp" "*.inc")
install (FILES ${header_files} DESTINATION include/androidjni)
