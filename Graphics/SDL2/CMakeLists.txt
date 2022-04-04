set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(
    arcade_sdl2
    SHARED
    SDLWindow.cpp
)

set(CXX_FLAGS "-lSDL_image" "-lSDL2_ttf")

set_property(TARGET arcade_sdl2 PROPERTY CXX_STANDARD 20)
set_property(TARGET arcade_sdl2 PROPERTY POSITION_INDEPENDENT_CODE ON)

target_include_directories(arcade_sdl2 PUBLIC
"${CMAKE_SOURCE_DIR}/Graphics/IWindow"
"${CMAKE_SOURCE_DIR}/Error"
${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_SHARED_LIBRARY_PREFIX "")

INCLUDE(FindPkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

include_directories(${SDL2_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
)

link_directories (${SDL2_LIBRARY_DIRS}
    ${SDL2_TTF_LIBRARY_DIRS}
)

target_link_libraries(arcade_sdl2 Graphics)
target_link_libraries(arcade_sdl2 Error)
target_link_libraries (arcade_sdl2 ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
