format:
    find . -type f -name "*.cpp" -o -name "*.hpp" | xargs clang-format -i
build:
    cd build && rm -rf * && cmake -DCMAKE_BUILD_TYPE=Release .. -GNinja && ninja && cd ..