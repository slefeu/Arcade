set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(
    Sfml
    SHARED
    SfWindow.cpp
    SfGraphic.cpp
)

set(CXX_FLAGS "-lsfml-graphics -lsfml-window")
find_package(SFML 2.5 
  REQUIRED 
    system window graphics network audio)

set_property(TARGET Sfml PROPERTY CXX_STANDARD 20)
target_include_directories(Sfml PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/Sfml")
target_include_directories(Sfml PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/Igraphic")
target_link_libraries(Sfml ${SFML_LIBRARIES})