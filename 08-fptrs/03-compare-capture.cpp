#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

struct CloserTo {
    int center;
    bool operator()(int a, int b) const {  //functor
        return std::abs(a - center) < std::abs(b - center);
    }
};

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6};
    CloserTo g{3};
    g(2, 3);
    sort(v.begin(), v.end(), g);
    for (int &x: v) {
        std::cout << x << "\n";
    }
}
