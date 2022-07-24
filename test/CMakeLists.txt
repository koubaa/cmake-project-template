project(divider_tests)

include_directories(${DIVISION_HEADERS_DIR})

set(SOURCE_FILES main.cpp src/test_divider_c.cpp src/test_divider_cxx.cpp)

SET(CMAKE_INSTALL_RPATH ${DIVISIBLE_INSTALL_BIN_DIR})

add_executable(divider_tests ${SOURCE_FILES})
target_link_libraries(divider_tests division)
install(TARGETS divider_tests DESTINATION bin)
