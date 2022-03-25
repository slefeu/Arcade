
add_library(
    Sfml
    SHARED
    SfWindow.cpp
    SfGraphic.cpp
)

set_property(TARGET Sfml PROPERTY CXX_STANDARD 20)
target_include_directories(Sfml PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/Sfml")
target_include_directories(Sfml PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/Igraphic")