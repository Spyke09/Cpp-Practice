template<typename T>
struct Foo {
    //void foo(Foo<T> &) {
    void foo(Foo &) {

    }
};

int main() {
    Foo<int> x, y;
    x.foo(y);
}