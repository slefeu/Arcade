add_library(
    Igraphic
    Utils.cpp
    AShape.cpp
    Text.cpp
)

set_property(TARGET Igraphic PROPERTY CXX_STANDARD 20)
set_property(TARGET Igraphic PROPERTY POSITION_INDEPENDENT_CODE ON)

target_include_directories(Igraphic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})