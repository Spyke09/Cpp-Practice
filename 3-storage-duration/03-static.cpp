#include <iostream>

struct Foo {
private:
    static inline int M = 10;
    static void foo() {
        M++;
    }

public:
    Foo() {
        std::cout << "Foo()\n";
    }
};

struct BigInt {
    static const BigInt ONE;

    BigInt(int) {}
};

const BigInt BigInt::ONE = 1;

Foo f;
int v; // static storage duration.

int main() {
    std::cout << "main() started\n";
}