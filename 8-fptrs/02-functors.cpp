#include <algorithm>
#include <vector>
#include <iostream>

struct Greater {
    bool operator() (int a, int b) const {  //functor
        return a > b;
    }
};

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6};
    Greater g;
    g(2, 3);
    sort(v.begin(), v.end(), g);
    for (int &x: v) {
        std::cout << x << "\n";
    }
}