#include <vector>
#include <cassert>
template<typename T>
void swap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename To, typename From>
To convert(From x) {
    return static_cast<To>(x);
}

template<template<typename> typename Container>
void foo(const Container<int> &) {
}

template<typename T>
void bar(const std::vector<T> &) {
}

template<typename C>
bool is_begin(const C &x, typename C::iterator it) {
    return x.begin() == it;
}

int main() {
    int x, y;
    swap<int>(x, y);

    // template argument deduction
    swap(x,y);

    [[maybe_unused]] auto z = convert<int, double>(10.5);
    [[maybe_unused]] auto z2 = convert<int>(10.5);

    foo(std::vector<int>{});
    bar(std::vector<int>{});

    std::vector<int> vec;
    assert(is_begin(vec, vec.end()));
}