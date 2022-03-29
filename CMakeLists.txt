cmake_minimum_required(VERSION 3.6)

# set the project name
project(arcade VERSION 0.1 LANGUAGES CXX)

#set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

option(OPTIMIZE_ACADE "Optimize arcade" ON)

if(OPTIMIZE_ACADE)
    set(CXX_FLAGS "-fconcepts-ts")
else ()
    set(CXX_FLAGS "-ggdb3")
endif()

set(HEADER_FILES ${PROJECT_SOURCE_DIR}/AGame/Arcade.hpp)

add_subdirectory(IGraphic)
add_subdirectory(SFML)

add_executable (${PROJECT_NAME}
    main.cpp
    Loader/Loader.cpp
    AGame/AGame.cpp
    AGame/Core.cpp
    AGame/Arcade.cpp
    Error/Error.cpp
    ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    "${CMAKE_SOURCE_DIR}/AGame"
    "${CMAKE_SOURCE_DIR}/Loader"
    "${CMAKE_SOURCE_DIR}/Error"
    "${CMAKE_SOURCE_DIR}/IGraphic"
)
#add_executable (${PROJECT_NAME} main.cpp)
#target_link_libraries(${PROJECT_NAME} PUBLIC Igame)
#target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

target_compile_options(${PROJECT_NAME} PUBLIC ${CXX_FLAGS})