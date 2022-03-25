format:
    find . -type f -name "*.cpp" -o -name "*.hpp" | xargs clang-format -i
build:
    cd build && cmake .. && cmake --build . && cd ..