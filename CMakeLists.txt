cmake_minimum_required(VERSION 3.19)
project(DRAW)

set(CMAKE_CXX_STANDARD 14)

link_directories(lib)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(DRAW
        main.cpp
        ${PROJECT_SOURCE_DIR}/src/datatypes.cpp
        ${PROJECT_SOURCE_DIR}/src/distance.cpp
        ${PROJECT_SOURCE_DIR}/src/draw.cpp
        ${PROJECT_SOURCE_DIR}/src/layout.cpp
        ${PROJECT_SOURCE_DIR}/src/linkedlist.cpp
        ${PROJECT_SOURCE_DIR}/src/misc.cpp
        )

target_link_libraries(DRAW ${PROJECT_SOURCE_DIR}/lib/libgraphics64.a)
target_link_libraries(DRAW -luuid -lmsimg32 -lgdi32 -limm32 -lole32 -loleaut32 -lwinmm -lgdiplus)
