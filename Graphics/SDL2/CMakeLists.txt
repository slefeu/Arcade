set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(
    arcade_sdl2
    SHARED
    SDLWindow.cpp
)

set_property(TARGET arcade_sdl2 PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade_sdl2 PROPERTY POSITION_INDEPENDENT_CODE ON)

target_include_directories(arcade_sdl2 PUBLIC
"${CMAKE_SOURCE_DIR}/Graphics/IWindow"
"${CMAKE_SOURCE_DIR}/Error"
${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
find_package(SDL2 REQUIRED)

target_link_libraries(arcade_sdl2 Graphics)
target_link_libraries(arcade_sdl2 Error)
target_link_libraries(arcade_sdl2 ${SDL2_LIBRARIES})