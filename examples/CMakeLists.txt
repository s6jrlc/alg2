#
# examples/CMakeLists.txt
#

file(GLOB examples *.cpp)
foreach (example IN LISTS examples)
	get_filename_component(example_name ${example} NAME_WE)
	add_executable(${example_name} ${example})
	add_dependencies(${PROJECT_NAME} ${example_name})
	target_include_directories(${example_name} PRIVATE ${PROJECT_SOURCE_DIR}/hdr)

	if (CXX_STANDARD_VERSION MATCHES 23)
		target_compile_features(${example_name} PUBLIC cxx_std_23)
	elseif (CXX_STANDARD_VERSION MATCHES 20)
		target_compile_features(${example_name} PUBLIC cxx_std_20)
	elseif (CXX_STANDARD_VERSION MATCHES 17)
		target_compile_features(${example_name} PUBLIC cxx_std_17)
	elseif (CXX_STANDARD_VERSION MATCHES 14)
		target_compile_features(${example_name} PUBLIC cxx_std_14)
	elseif (CXX_STANDARD_VERSION MATCHES 11)
		target_compile_features(${example_name} PUBLIC cxx_std_11)
	endif()
endforeach()
