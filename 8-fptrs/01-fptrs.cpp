#include <iostream>

void print(int x) {
    std::cout << x << "\n";
}

void print_twice(int x) {
    std::cout << x << " " << x << "\n";
}

// сишный синтаксис
void apply(void (*operation)(int)) {
    std::cout << "aboba\n";
    operation(10);
}

using ApplyArg = void(*)(int);
void apply2(ApplyArg operation) {
    std::cout << "aboba\n";
    operation(10);
}

int main() {
    apply(print);
    apply(print_twice);

}