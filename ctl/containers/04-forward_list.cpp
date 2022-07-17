#include <iostream>
#include <forward_list>

template<typename T>
void printColection(const T &l) {
    for (const auto &i : l) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::forward_list<int> fl = {1, 2, 3, 4};

    fl.push_front(1);
    fl.pop_front();

    printColection(fl);

    fl.insert_after(fl.begin(), 200);
    printColection(fl);

    fl.insert_after(fl.before_begin(), 200);
    printColection(fl);
}