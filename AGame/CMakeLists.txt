add_library(
    AGame
    AGame.cpp
    Core.cpp
    Arcade.cpp
)

target_include_directories(AGame PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/Error" "${CMAKE_SOURCE_DIR}/IGraphic")