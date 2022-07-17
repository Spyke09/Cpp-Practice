#include <iostream>
#include <deque>

template<typename T>
void printList(const T &l) {
    for (const auto &i : l) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    // реализован как список маленьких векторов 
    // компромис по скорости между вектором и листом
    // все методы те же самые
    std::deque<int> dq = {1, 9, 12};
    printList(dq);
}
