set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(
    arcade_centipede
    SHARED
    Centipede.cpp
)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set_property(TARGET arcade_centipede PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET arcade_centipede PROPERTY CXX_STANDARD 20)
target_include_directories(arcade_centipede PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
"${CMAKE_SOURCE_DIR}/ArcadeCore"
"${CMAKE_SOURCE_DIR}/Graphics/IWindow"
"${CMAKE_SOURCE_DIR}/Games/"
)

target_link_libraries(arcade_centipede Graphics)