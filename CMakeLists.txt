cmake_minimum_required(VERSION 3.12)


set(PROJECT "CppCmakeProject")
set(CONFIG_H "ProjectConfig.h")
set(CONFIG_IN_H "ProjectConfig.h.in")


project(${PROJECT}_Project VERSION 1.1.0 LANGUAGES CXX)

# Glocal CMake variables are set here
set(CMAKE_CXX_STANDARD           17)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_EXTENSIONS         OFF)


# Project / Library Names
set(LIBRARY_NAME "${PROJECT}_MyLib")
set(LIBRARY_LINALG "${PROJECT}_LinAlg")
set(MAIN "${PROJECT}_Executeable")
set(TEST_MAIN "${PROJECT}_unit_tests")
# Target
set(BENCH_MARK_MAIN "${PROJECT}_benchmark")


# Options for generating/building
# cd build && make -DUSE_PRINTF=[ON|OFF] .. (in build folder)
option(USE_PRINTF "If you want either to use printf (ON) or cout (OFF)" OFF)

option(USE_GCOV "Create a GCov-enables build." OFF)


option(ENABLE_BENCHMARKING "Enable Benchmarking" OFF)

# Add external
add_subdirectory(external)

# Configuration Files
configure_file(${PROJECT_SOURCE_DIR}/include/${CONFIG_IN_H} ${PROJECT_BINARY_DIR}/${CONFIG_H} @ONLY)

#inlcude own cmake modules

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(Documentation)
include(CTest)

if(USE_GCOV)
	if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|CLang")
		include(CodeCoverage)
	else()
		message("You mus use GNU or CLang Compiler for CodeCoverage!")
	endif()
endif()

# Add conan packages
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()




#libraries
add_subdirectory(src)

#executeables
add_subdirectory(app)

add_subdirectory(tests)

if(ENABLE_BENCHMARKING)
	add_subdirectory(benchmarks)
endif()