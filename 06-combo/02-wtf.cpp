#include <iostream>

template<typename T>
struct Foo {
    T value;
    void foo() {
        // не скомпилируется
        // value.foo<int>();
        // правильно:
        value.template foo<int>();
    }
};

int main() {

}