#include <vector>
#include <iostream>

template<typename C>
void printAll(const C &container) {
    for (const auto &item : container) {
        std::cout << item << "\n";
    }
}

// с 20х плюсов есть
void printAll2(const auto &container) {
    for (const auto &item : container) {
        std::cout << item << "\n";
    }
}

bool operator==(const auto &, const auto &) {
    cout<<"пиздец\n";
    return true;
}

int main() {
    int arr[] = {1, 2, 3};
    std::vector<int> vec = {4, 5, 6};
    printAll(arr);
    printAll(vec);
}