set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(
    arcade_sdl2
    SHARED
    SDLWindow.cpp
)

set_property(TARGET arcade_sfml PROPERTY POSITION_INDEPENDENT_CODE ON)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
find_package(Curses REQUIRED)

set_property(TARGET arcade_sdl2 PROPERTY CXX_STANDARD 20)
target_include_directories(arcade_sdl2 PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}
"${CMAKE_SOURCE_DIR}/IGraphic"
"${CMAKE_SOURCE_DIR}/Error"
)


target_link_libraries(arcade_sdl2 ${CURSES_LIBRARIES})
target_link_libraries(arcade_sdl2 Igraphic)