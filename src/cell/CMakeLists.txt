project(cell)

set(TARGET cell)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${TARGET} cell.cpp)

target_link_libraries(${TARGET} app)
