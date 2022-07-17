#include <iostream>

struct Foo {
    //C++03: Safe bool idiom.
    //C++11:
    explicit operator bool() {
        return true;
    }
};

int main() {
    Foo f;
    if (f) {

    }

    //std::cout<< (10 + f)<<"\n";
}