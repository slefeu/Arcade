add_library(
    Loader
    Loader.cpp
)

set_property(TARGET Loader PROPERTY CXX_STANDARD 20)

target_include_directories(Loader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/IGraphic" "${CMAKE_SOURCE_DIR}/Error")