#include <cassert>
#include <iostream>

struct Foo {
    explicit operator int() {
        return 123;
    }
};

struct Foo2 {
    operator int() {
        return 123;
    }
};

void foo([[maybe_unused]]int) {

}

int main() {
    Foo f;
    Foo2 f2;
    //int x1 = f;
    //x3 = f;
    //foo(f); 
    [[maybe_unused]]int x2(f);
    [[maybe_unused]]int x3{f};
    foo(static_cast<int>(f)); 
    foo(f2);
    foo(static_cast<int>(f2));
    
}