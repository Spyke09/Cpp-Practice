#include <cassert>
#include <iostream>

struct Foo {
    explicit operator int() {
        return 123;
    }
};

void foo(int c) {

}

int main() {
    Foo f;
    //int x1 = f;
    //x3 = f;
    //foo(f); 
    [[maybe_unused]]int x2(f);
    [[maybe_unused]]int x3{f};
    foo(static_cast<int>(f)); 
}