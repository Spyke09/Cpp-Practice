// C++17: class template argument deduction (ctad)

template<typename T>
struct Foo {
    T value;
    Foo() {};
    Foo(T value_) : value(value_) {}
};

int main() {
    [[maybe_unused]] auto x = Foo(10);
    [[maybe_unused]] Foo y(20);
    [[maybe_unused]] Foo<int> z;
}