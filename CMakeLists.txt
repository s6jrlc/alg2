#[[
	alg2: algebra algorithm

	${PROJECT_SOURCE_DIR}/CMakeLists.txt
]]

cmake_minimum_required(VERSION 3.15...${CMAKE_VERSION})

set(MAJOR "1")
set(MINOR "0")
set(PATCH "0")
project(alg2
	VERSION "${MAJOR}.${MINOR}.${PATCH}")
unset(MAJOR)
unset(MINOR)
unset(PATCH)
if (NOT DEFINED CXX_STANDARD_VERSION)
	set(CXX_STANDARD_VERSION 17 CACHE STRING "C++ standard ver.")
endif ()

add_subdirectory(hdr)
add_subdirectory(examples EXCLUDE_FROM_ALL)
