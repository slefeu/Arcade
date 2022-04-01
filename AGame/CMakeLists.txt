add_library(
    AGame
    Core.cpp
    IGame.cpp
    Arcade.cpp
)

set_property(TARGET AGame PROPERTY CXX_STANDARD 20)
set(CXX_FLAGS "-g")

target_include_directories(AGame PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
"${CMAKE_SOURCE_DIR}/IGraphic"
"${CMAKE_SOURCE_DIR}/Error"
"${CMAKE_SOURCE_DIR}/Loader")

target_link_libraries(AGame Igraphic)
target_link_libraries(AGame Loader)