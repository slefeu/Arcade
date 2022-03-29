add_library(
    game
    AGame.cpp
    Core.cpp
    Arcade.cpp
)

target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/AGame")