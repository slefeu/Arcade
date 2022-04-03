set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(
    arcade_centipede
    SHARED
    Centipede.cpp
)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set_property(TARGET arcade_centipede PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET arcade_centipede PROPERTY CXX_STANDARD 20)
target_include_directories(arcade_centipede PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/AGame" "${CMAKE_SOURCE_DIR}/IGraphic")
target_link_libraries(arcade_centipede Igraphic)
target_link_libraries(arcade_centipede AGame)