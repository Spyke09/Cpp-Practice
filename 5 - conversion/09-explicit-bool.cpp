#include <iostream>

struct Foo {
    //Safe bool idiom.
    explicit operator bool() {
        return true;
    }
};

int main() {
    Foo f;
    if (f) {

    }

    std::cout<< (10 + f)<<"\n";
}