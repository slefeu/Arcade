add_library(
    Error
    Error.cpp
)

set_property(TARGET Error PROPERTY POSITION_INDEPENDENT_CODE ON)

target_include_directories(Error PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})