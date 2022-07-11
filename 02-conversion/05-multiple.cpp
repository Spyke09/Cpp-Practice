struct Foo {

};

struct Bar {
    Bar() {}
    Bar(Foo) {}
};

struct Baz {
    Baz() {}
    Baz(Bar) {}
};

int main() {
    [[maybe_unused]] Foo foo;
    [[maybe_unused]] Bar bar;
    [[maybe_unused]] Baz baz;
    foo = foo;
    //foo = bar;
    bar = foo;
    bar = bar;
    //bar = baz;
    baz = bar;
    //baz = foo;
    baz = Bar(foo);
}
