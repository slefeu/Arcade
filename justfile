format:
    find . -type f -name "*.cpp" -o -name "*.hpp" | xargs clang-format -i
build:
    cd build && rm -rf * && cmake .. -GNinja && ninja && cd ..