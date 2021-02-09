add_library(${LIBRARY_NAME} OBJECT "my_lib.cpp")
target_include_directories(${LIBRARY_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_17)

target_link_libraries(${LIBRARY_NAME} PUBLIC ${LIBRARY_LINALG})
target_link_libraries(${LIBRARY_NAME} PUBLIC loguru)
target_link_libraries(${LIBRARY_NAME} PUBLIC ${CONAN_CXXOPTS})