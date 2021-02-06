# Main Executeable
add_executable(${MAIN} main.cc)
target_link_libraries(${MAIN} PUBLIC ${LIBRARY_NAME})
target_include_directories(${MAIN} PUBLIC ${PROJECT_BINARY_DIR})
target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_17)

target_link_libraries(${LIBRARY_NAME} PUBLIC ${CONAN_CXXOPTS})