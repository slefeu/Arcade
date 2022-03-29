add_library(
    AGame
    Core.cpp
    AGame.cpp
    Arcade.cpp
)

set_property(TARGET AGame PROPERTY CXX_STANDARD 20)

target_include_directories(AGame PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/IGraphic" "${CMAKE_SOURCE_DIR}/Error" "${CMAKE_SOURCE_DIR}/Loader")