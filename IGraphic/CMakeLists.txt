add_library(
    Igraphic
    State.cpp
    AWindow.cpp
    AShape.cpp
    Text.cpp
)

target_include_directories(Igraphic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})