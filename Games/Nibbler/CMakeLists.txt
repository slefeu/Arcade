set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(
    arcade_nibbler
    SHARED
    Nibbler.cpp
)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set_property(TARGET arcade_nibbler PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET arcade_nibbler PROPERTY CXX_STANDARD 20)
target_include_directories(arcade_nibbler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
"${CMAKE_SOURCE_DIR}/Graphics/IWindow"
"${CMAKE_SOURCE_DIR}/Graphics/Error"
"${CMAKE_SOURCE_DIR}/Games/"
)

target_link_libraries(arcade_nibbler Graphics)
target_link_libraries(arcade_nibbler Error)