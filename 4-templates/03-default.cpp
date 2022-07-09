#include <iostream>
#include <vector>
#include <set>
#include <utility>

template<typename C = int, typename = char, typename = double, int = 10>
struct teml_foo {
};

template<typename C, C value>
struct teml_bar {
};

template<template<typename> typename Container, typename T>
struct temp_baz {
    Container<std::pair<T, T>> container;
};

int main() {
    [[maybe_unused]] teml_foo<std::vector<int>, char, bool> x;
    [[maybe_unused]] teml_foo<std::vector<int>> y;
    [[maybe_unused]] teml_foo<> x;

    [[maybe_unused]] teml_bar<int, 10> x1;
    // здесь именно std::vector, а не vector<...>
    [[maybe_unused]] temp_baz<std::vector, int> x2;
}