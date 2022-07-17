struct Bar;

struct Foo {
    Foo() {}
    Foo(Bar);
};

struct Bar {
    operator Foo() { return {}; }
};

Foo::Foo(Bar) {};

int main () {
    Foo f;
    Bar b;
    //f = b;
    f = b.operator Foo();
    f = Foo(b);
}