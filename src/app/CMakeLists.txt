project(app)

set(TARGET app)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                    ../cell/include)

add_library(${TARGET} app.cpp)
