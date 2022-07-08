struct Foo {
    explicit Foo() {
    }
    explicit Foo(int, int) {
    }
};

int main() {
    //[[maybe_unused]]Foo f = {123, 123};
    //Foo f2 = {1, 2};
    Foo f3;
}