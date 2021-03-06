#include <algorithm>
#include <iostream>

template<typename T>
void foo(const T &) {
    std::cout << "1\n";
}

template<>
void foo(const char &) { // Not 'char', argument should be the same.
    std::cout << "2\n";
}

void foo(double) {
    std::cout << "3\n";
}

int main() {
    foo(10);
    foo('x');
    foo(10.0);
    foo<double>(10.0);
}

auto foo3(auto) {
    return true;
}