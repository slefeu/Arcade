add_library(
    Graphics
    Utils.cpp
    AShape.cpp
    Text.cpp
)

set_property(TARGET Graphics PROPERTY CXX_STANDARD 20)
set_property(TARGET Graphics PROPERTY POSITION_INDEPENDENT_CODE ON)

target_include_directories(Graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})