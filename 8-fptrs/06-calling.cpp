#include <iostream>

template<typename F>
void apply(F op) {
    std::cout << "aboba\n";
    op(10);
}

struct Print {
    void operator()(int x) const {
        std::cout << x << "\n";
    }
};

struct Print2 {
    void operator()(int x) const {
        std::cout << x << ',' << x << "\n";
    }
};

int main() {
    apply(Print{});
    apply(Print2{});
};