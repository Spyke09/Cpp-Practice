#include <iostream>
#include <vector>
#include <set>
#include <utility>

template<typename C = int, typename = char, typename = double, int = 10>
struct templ_foo {
};

template<typename C, C value>
struct templ_bar {
};

// template<template<typename> typename Container, typename T>
// struct templ_baz {
//     Container<std::pair<T, T>> container;
// };

int main() {
    [[maybe_unused]] templ_foo<std::vector<int>, char, bool> x;
    [[maybe_unused]] templ_foo<std::vector<int>> y;
    [[maybe_unused]] templ_foo<> z;
    [[maybe_unused]] templ_bar<int, 10> x1;
    // здесь именно std::vector, а не vector<...>
    // [[maybe_unused]] templ_baz<std::vector, int> x2;
}