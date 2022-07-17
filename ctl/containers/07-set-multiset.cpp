#include <set>
#include <iostream>

template<typename T>
void printColection(const T &l) {
    for (const auto &i : l) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

struct MyKey {
private:
    int key;
public:
    MyKey(int a): key(a) {}
    int getKey() const{
        return key;
    }

    bool operator<(const MyKey &other) const {
        return abs((*this).key) < abs(other.key);
    }

    friend std::ostream& operator<<(std::ostream& strm, const MyKey &a) {
        strm << a.key;
        return strm;
    }
};


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

    std::set<MyKey> s2;
    s2.insert(-2);
    s2.insert(3);
    s2.insert(-4);
    s2.insert(5);
    printColection(s2);

    auto cmp = [](int a, int b) { return abs(a) < abs(b); };
    std::set<int, decltype(cmp)> s3(cmp);
    s3.insert(-2);
    s3.insert(3);
    s3.insert(-4);
    s3.insert(5);
    printColection(s3);
}