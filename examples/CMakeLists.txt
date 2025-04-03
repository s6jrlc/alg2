#
# examples/CMakeLists.txt
#

file(GLOB examples *.cpp)
foreach (example IN LISTS examples)
	get_filename_component(example_name ${example} NAME_WE)
	add_executable(${example_name} ${example})
	add_dependencies(${PROJECT_NAME} ${example_name})
	target_include_directories(${example_name} PRIVATE ${PROJECT_SOURCE_DIR}/hdr)

	set_property(TARGET ${example_name} PROPERTY CXX_STANDARD ${CXX_STANDARD_VERSION})
endforeach()
