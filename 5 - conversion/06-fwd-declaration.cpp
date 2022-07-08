struct Bar;

struct Foo {
    Foo(Bar);
};

struct Bar {
    Bar(Foo) {}
};

Foo::Foo(Bar) {}

int main () {
    
}