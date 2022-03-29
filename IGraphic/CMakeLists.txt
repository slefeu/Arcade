add_library(
    Igraphic
    State.cpp
    AWindow.cpp
    AShape.cpp
    Text.cpp
)

set_property(TARGET Igraphic PROPERTY CXX_STANDARD 20)

target_include_directories(Igraphic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})