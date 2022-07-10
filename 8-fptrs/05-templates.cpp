#include <algorithm>
#include <set>
#include <iostream>

template<typename T>
struct Greater1 {
    bool operator()(const T &a, const T &b) const { 
        return a > b;
    }
};

struct Greater2 {
    template<typename T>
    bool operator()(const T &a, const T &b) const { 
        return a > b;
    }
};

int main() {
    std::set<int, Greater1<int>> v1{1, 2, 3, 4, 5, 6};
    std::set<int, Greater2> v2{1, 2, 3, 4, 5, 6};
    for (int x : v1) {
            std::cout << x << "\n";
    }
    std::cout << "=====\n";
    for (int x : v2) {
            std::cout << x << "\n";
    }
}