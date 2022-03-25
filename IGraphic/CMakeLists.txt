add_library(
    Igraphic
    State.cpp
)

target_include_directories(Igraphic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/Igraphic")