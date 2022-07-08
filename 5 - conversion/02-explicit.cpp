#include <string>

struct BigInt {
    explicit BigInt(std::string) {}
};

void foo(int) {}
void foo(double) {}
void foo(BigInt) {}
void bar(std::string) {}

int main() {
    double x = 10;
    foo(x);
    foo(static_cast<int>(x));
    std::string y = "asdasd";
    foo(static_cast<BigInt>(y));
    foo(BigInt(y));
}