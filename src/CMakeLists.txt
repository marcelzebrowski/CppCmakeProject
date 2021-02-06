#mylib library
set(LIBRARY_SRC "my_lib.cc")
set(LIBRARY_INCLUDES ${PROJECT_SOURCE_DIR}/include)
add_library(${LIBRARY_NAME} OBJECT ${LIBRARY_SRC})


target_link_libraries(${LIBRARY_NAME} PUBLIC ${LIBRARY_LINALG})
target_link_libraries(${LIBRARY_NAME} PUBLIC loguru)





# we add the directory to the library
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})
target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_17)
