#include <algorithm>
#include <set>
#include <iostream>

struct Greater {
    bool operator()(int a, int b) const {  //functor
        return a > b;
    }
};

struct CloserTo {
    int center;
    bool operator()(int a, int b) const {  //functor
        return std::abs(a - center) < std::abs(b - center);
    }
};

int main() {
    std::set<int, Greater> v1{1, 2, 3, 4, 5, 6};
    //std::set<int, CloserTo> v2{1, 2, 3, 4, 5, 6};
    std::set<int, CloserTo> v2({1, 2, 3, 4, 5, 6}, CloserTo{3});
}