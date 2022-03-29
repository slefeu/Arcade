set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(
    arcade_ncurse
    SHARED
    NcWindow.cpp
)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
find_package(Curses REQUIRED)

set_property(TARGET arcade_ncurse PROPERTY CXX_STANDARD 20)
target_include_directories(arcade_ncurse PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/IGraphic")

target_link_libraries(arcade_ncurse ${CURSES_LIBRARIES})