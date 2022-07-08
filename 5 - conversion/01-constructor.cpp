#include <cassert>
#include <iostream>

struct BigInt {
    BigInt(int x) {
        static_cast<void>(x);
        [[maybe_unused]]int a;
    }
};

void foo(BigInt) {
    
}

BigInt bar() {
    return 40;
}

int main() {
    BigInt a = 10;
    a = 12;
    foo(23);
    [[maybe_unused]]int y = 30.5;
}