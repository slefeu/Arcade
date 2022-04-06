cmake_minimum_required(VERSION 3.6)

project(arcade VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

option(OPTIMIZE_ACADE "Optimize arcade" ON)

if(OPTIMIZE_ACADE)
    set(CXX_FLAGS "-ggdb3")
else ()
    set(CXX_FLAGS "-ggdb3")
endif()

set(HEADER_FILES ${PROJECT_SOURCE_DIR}/ArcadeCore/Arcade.hpp)

add_subdirectory(Graphics/IWindow)
add_subdirectory(Error)
add_subdirectory(Graphics/SFML)
add_subdirectory(Graphics/Ncurse)
add_subdirectory(Graphics/SDL2)
add_subdirectory(Loader)
add_subdirectory(ArcadeCore)
add_subdirectory(Games/Centipede)
add_subdirectory(Games/Nibbler)

add_executable(${PROJECT_NAME}
    main.cpp
    ${HEADER_FILES}
)

target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS})
target_link_libraries(${PROJECT_NAME} ArcadeCore)
target_link_libraries(${PROJECT_NAME} Error)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    "${CMAKE_SOURCE_DIR}/ArcadeCore"
    "${CMAKE_SOURCE_DIR}/Loader"
    "${CMAKE_SOURCE_DIR}/Error"
    "${CMAKE_SOURCE_DIR}/Graphics/IWindow"
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

target_compile_options(${PROJECT_NAME} PUBLIC ${CXX_FLAGS})