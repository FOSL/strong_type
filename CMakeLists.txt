project(FOSL-strong_type CXX)

set(PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/source")

add_library(
	${PROJECT_NAME}

	${PROJECT_SOURCE_DIR}/FOSL/strong_type.cpp
	${PROJECT_SOURCE_DIR}/FOSL/strong_type.hpp

	${PROJECT_SOURCE_DIR}/FOSL/strong_type/value_wrapper.hpp
# 	${PROJECT_SOURCE_DIR}/FOSL/strong_type/named_type.hpp
# 	${PROJECT_SOURCE_DIR}/FOSL/strong_type/unit.hpp
)

target_include_directories(
	${PROJECT_NAME} PUBLIC

	${PROJECT_SOURCE_DIR}
)

target_link_libraries(
	${PROJECT_NAME}

	FOSL-metaprogramming
)

add_subdirectory(test)
add_test(NAME unsorted COMMAND unsorted.elf)
