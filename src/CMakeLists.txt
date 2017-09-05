project(main)

add_executable(${EXECUTABLE_NAME} main.cpp)

find_package(SFML 2 REQUIRED network audio graphics window system)

add_subdirectory(app)
add_subdirectory(cell)

target_link_libraries(${EXECUTABLE_NAME} app cell)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

