#include <iostream>
#include <vector>
// class template
template<typename T, int V>
struct templ_foo {
    T value{};
    bool exist{}; //the most vexing parse

    void foo(T &value) {
        value.push_back(30);
    }
};

int main() {
    {
        [[maybe_unused]] templ_foo<int, 10> x;
        [[maybe_unused]] templ_foo<int, 10> y;
        x = y;
        int my_int;
        //x.foo(my_int);
    }
    {
        [[maybe_unused]] templ_foo<int, 10> x;
        [[maybe_unused]] templ_foo<int, 11> y;
        //x = y;
    }
    {
        [[maybe_unused]] templ_foo<std::vector<int>, 10> x;
        [[maybe_unused]] templ_foo<int, 11> y;
        std::vector<int> vec{};
        x.foo(vec);
    }

}
