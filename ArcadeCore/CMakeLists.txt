add_library(
    ArcadeCore
    Core.cpp
    Arcade.cpp
)

set_property(TARGET ArcadeCore PROPERTY CXX_STANDARD 20)

target_include_directories(ArcadeCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
"${CMAKE_SOURCE_DIR}/Graphics/IWindow"
"${CMAKE_SOURCE_DIR}/Error"
"${CMAKE_SOURCE_DIR}/Loader"
"${CMAKE_SOURCE_DIR}/Games/"
)

target_link_libraries(ArcadeCore Graphics)
target_link_libraries(ArcadeCore Loader)