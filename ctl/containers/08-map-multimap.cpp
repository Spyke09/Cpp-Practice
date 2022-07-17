#include <map>
#include <iostream>

template<typename T>
void printColection(const T &l) {
    for (const auto &i : l) {
        std::cout << '(' << i.first << ", " << i.second << ") ";
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
    std::map<int, int> s;
    s.insert({5, 1});
    s.insert({1, 2});
    s.insert({12, 3});
    s.insert({4, 4});

    s.insert({-1, 52424});
    s.insert({-1, 5}); // значение не поменяется

    s.erase(-1);
    s.insert({-1, 5}); // значение поменяется

    s.emplace(7, 6);
    s.emplace(7, 5454521); // значение не поменяется
    printColection(s);

    std::cout << (*s.find(12)).second << '\n';
    std::cout << s[12] << '\n';
    s[12] = 1212;
    std::cout << s[12] << '\n';
    s[-122] = 122;
    std::cout << s[-122] << '\n';

    // работа at() аналогично, но будет бросаться исключение при не сущю ключе
    // multimap будет работать аналогично
    // не будет перегрузки []
}