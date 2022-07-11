#include <iostream>

struct Foo {
    int x;
    Foo(int i) : x(i) {}

    operator int() const {
        std::cout<<"operator called\n";
        return 123;
    }
    // operator const int&() const{
    //     std::cout<<"operator called\n";
    //     return x;
    // }

    operator int&() {
        std::cout<<"operator called\n";
        return x;
    }
};

int main() {
    Foo f = 10;
    [[maybe_unused]]int x = f;
}