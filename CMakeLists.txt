cmake_minimum_required(VERSION 3.6)

# set the project name
project(arcade VERSION 0.1 LANGUAGES CXX)

#set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

option(OPTIMIZE_ACADE "Optimize arcade" ON)

if(OPTIMIZE_ACADE)
    set(CXX_FLAGS "-fconcepts-ts")
else ()
    set(CXX_FLAGS "-ggdb3")
endif()

#set(HEADERS ${PROJECT_SOURCE_DIR}/Acomponent/Acomponent.hpp)

add_subdirectory(Igraphic)
#add_subdirectory(Igame)
add_subdirectory(Sfml)
#add_executable (${PROJECT_NAME} main.cpp ${HEADER_FILES})
add_executable (${PROJECT_NAME} main.cpp core.cpp)
#target_link_libraries(${PROJECT_NAME} PUBLIC Igame)
#target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

target_compile_options(${PROJECT_NAME} PUBLIC ${CXX_FLAGS})