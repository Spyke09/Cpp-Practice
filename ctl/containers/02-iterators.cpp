#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3, 7, 1, 4};

    std::vector<int>::iterator it, it2;
    it = v.begin();

    std::cout << *it << '\n';

    *it = 100;
    std::cout << *it << '\n';
    
    it += 2;
    std::cout << *it << '\n';
    it -= 2;
    std::cout << *it << '\n';

    for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); i++) {
        std::cout << *i << ' ';
    }
    std::cout << '\n';
    // или так
    for (std::vector<int>::const_iterator i = v.cbegin(); i != v.cend(); i++) {
        std::cout << *i << ' ';
    }
    std::cout << '\n';
    // в обратную сторону
    for (std::vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); i++) {
        std::cout << *i << ' ';
    }
    std::cout << '\n';

    it = v.begin();
    advance(it, 3);
    std::cout << *it << '\n';

    it = v.begin();
    advance(it, 2);
    v.insert(it, 999);
    for (int i : v) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    it = v.begin();
    advance(it, 4);
    v.erase(it);
    for (int i : v) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    v = {1, 2, 3, 7, 1, 4};
    it = v.begin(), it2 = v.begin();
    advance(it, 4);
    advance(it2, 6);
    v.erase(it, it2);
    for (int i : v) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}