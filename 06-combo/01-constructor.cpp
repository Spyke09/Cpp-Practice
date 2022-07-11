#include <iostream>

template<typename T, int Value>
struct Foo {
    Foo() {}
    template<int Value2>
    Foo(const Foo<T, Value2> &) {
        std::cout << Value2 << "-->" << Value << "\n";
    }

    template<typename T2>
    Foo(const Foo<T2, Value> &) {
        std::cout << "aboba\n";
    }

    template<typename T2, int Value2>
    Foo(const Foo<T2, Value2> &) {
        std::cout << "abigus\n";
    }

    template<typename W>
    void foo(const W&) {
    }
};

int main() {
    [[maybe_unused]] Foo<int, 10> x;
    [[maybe_unused]] Foo<int, 11> y;
    [[maybe_unused]] Foo<char, 11> z;

    x = y;
    y = z;
    [[maybe_unused]] Foo<int, 10> a = z;
    x.foo(10);
}