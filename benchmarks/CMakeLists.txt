# Sources
set(BENCHMARK_SOURCES "main.cc")




add_executable(${BENCH_MARK_MAIN} ${BENCHMARK_SOURCES})


# Settings

target_compile_features(${BENCH_MARK_MAIN} PUBLIC cxx_std_17)
target_link_libraries(${BENCH_MARK_MAIN} PUBLIC ${LIBRARY_NAME}) # diese soll gebenchmarkt werden
target_link_libraries(${BENCH_MARK_MAIN} PUBLIC ${CONAN_LIBS_CELERO})