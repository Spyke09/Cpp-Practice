struct Foo {
    explicit Foo() {
    }
    explicit Foo(int, int) {
    }
};

// Foo foo() {
//     return {10, 20};
// }

void bar(Foo) {
}

int main() {
    //[[maybe_unused]]Foo f = {123, 123};
    //Foo f2 = {1, 2};
    Foo f3;
    //bar({10, 20});
}