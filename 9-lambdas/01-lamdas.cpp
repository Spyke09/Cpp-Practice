#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6};
    auto g = [](int a, int b) { return a > b; };
    g(2, 3);
    sort(v.begin(), v.end(), g);
    for (int &x: v) {
        std::cout << x << "\n";
    }
}