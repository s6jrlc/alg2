#
# hdr/CMakeLists.txt
#

file(GLOB headers
	${CMAKE_CURRENT_SOURCE_DIR}/alg2/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/alg2/*/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/alg2/*/*/*.hpp
)

add_library(${PROJECT_NAME} INTERFACE ${headers})

foreach(hdr IN LISTS headers)
  if (IS_ABSOLUTE "${hdr}")
    file(RELATIVE_PATH hdr "${CMAKE_CURRENT_SOURCE_DIR}" "${hdr}")
  endif()
  get_filename_component(hdr_path "${hdr}" PATH)
  string(REPLACE "/" "\\" hdr_path_ide "${hdr_path}")
	#message(${hdr})
  source_group("${hdr_path_ide}" FILES "${hdr}")
endforeach()

install(DIRECTORY alg2 DESTINATION include)
