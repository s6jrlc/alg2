# options:
# CXX_STANDARD_11
# CXX_STANDARD_14

cmake_minimum_required(VERSION 2.4)

project(alg2)

#set(CMAKE_SUPPRESS_REGENERATION true)
if (CXX_STANDARD_14)
  #add_definitions(-std=c++14 -Wall)
  set(CMAKE_CXX_FLAGS "-std=c++14 -Wall")
elseif (CXX_STANDARD_11)
  #add_definitions(-std=c++11 -Wall)
  set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
else()
  #add_definitions(-Wall)
  set(CMAKE_CXX_FLAGS "-Wall")
endif()

if (CMAKE_GENERATOR MATCHES "MinGW" 
    OR CMAKE_GENERATOR MATCHES "MSYS"
    OR (WIN32 AND CMAKE_GENERATOR MATCHES "Unix"))
  set(CMAKE_C_COMPILER clang)
  set(CMAKE_CXX_COMPILER clang++)
  include_directories(/mingw64/include)
  link_directories(/mingw64/lib)
elseif (APPLE)
  set(CMAKE_C_COMPILER /usr/bin/clang)
  set(CMAKE_CXX_COMPILER /usr/bin/clang++)
  include_directories(/usr/local/include)
  link_directories(/usr/local/lib)
elseif(UNIX)
endif ()

file(GLOB headers alg2/*.hpp alg2/*/*.hpp alg2/*/*/*.hpp)

include_directories(.)
add_subdirectory(test)

add_executable(alg2_test ${headers})
add_executable(alg2_test test/test.cpp)

foreach(hdr IN LISTS headers)
  if (IS_ABSOLUTE "${hdr}")
    file(RELATIVE_PATH hdr_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${hdr}")
  else()
    set(hdr_rel "${hdr}")
  endif()
  get_filename_component(hdr_path "${hdr_rel}" PATH)
  string(REPLACE "/" "\\" hdr_path_ide "${hdr_path}")
  message(${hdr_rel})
  source_group("${hdr_path_ide}" FILES "${hdr}")
endforeach()

install(DIRECTORY alg2 DESTINATION include)
