add_library(
    error
    Error.cpp
)

target_include_directories(error PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/Error")