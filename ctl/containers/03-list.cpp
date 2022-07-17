#include <iostream>
#include <list>

template<typename T>
void printColection(const T &l) {
    for (const auto &i : l) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::list<int> l = {7, 5, 1, 3};
    l.push_back(1);
    l.push_front(2);

    printColection(l);
    
    l.sort();
    printColection(l);

    // O(n)
    l = {7, 5, 1, 1, 1, 3, 1, 1, };    
    l.unique();
    printColection(l);

    l.reverse();
    printColection(l);

    l.clear();

    l.insert(l.begin(), 12);
    auto it = l.begin();
    advance(it, 3);
    l.erase(l.begin(), it);

    l = {7, 5, 1, 3};
    l.remove(5);
    printColection(l);

    l.assign(3, 12);
    printColection(l);

    std::list<int> l2 = {1, 2, 3, 4, 5};
    l.assign(l2.begin(), l2.end());
    printColection(l2);
}