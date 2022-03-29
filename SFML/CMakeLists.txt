set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(
    arcade_sfml
    SHARED
    SfWindow.cpp
)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
find_package(SFML 2.5
  REQUIRED
    system window graphics network audio)

set_property(TARGET arcade_sfml PROPERTY CXX_STANDARD 20)
target_include_directories(arcade_sfml PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/IGraphic")

target_link_libraries(arcade_sfml Igraphic)
target_link_libraries(arcade_sfml sfml-graphics sfml-window sfml-audio)
target_link_libraries(arcade_sfml ${SFML_LIBRARIES})