#include <iostream>
#include <array>

template<typename T>
void printColection(const T &l) {
    for (const auto &i : l) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::array<int, 4> a = {1, 2, 3, 4};
    // std::array<int, 4> a = {1, 2, 3, 4, 5}; - не сработает
    printColection(a);
    
    a.fill(-1);
    printColection(a);

}