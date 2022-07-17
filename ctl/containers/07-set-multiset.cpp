#include <set>
#include <iostream>

template<typename T>
void printColection(const T &l) {
    for (const auto &i : l) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(12);
    s.insert(4);
    s.insert(-1);
    printColection(s);

    s = {1, 44, 6, -2, 43};
    printColection(s);
    
    s.erase(44);
    printColection(s);
    
    [[maybe_unused]] auto it1 = s.find(6);
    [[maybe_unused]] auto it2 = s.find(7); //  = s.end()

    std::multiset<int> ms = {1, 1, 3, 7, 7, 4};
    printColection(ms);

    [[maybe_unused]] auto it3 = ms.lower_bound(3);
    [[maybe_unused]] auto it4 = ms.upper_bound(3);
    std::cout << *it3 << '\n';
    std::cout << *it4 << '\n';

    [[maybe_unused]] auto a = ms.equal_range(1);
    std::cout << "(" << *a.first << ", " << *a.second << ")\n";
}