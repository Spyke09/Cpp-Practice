template<typename> struct Templ1 {};
template<template<typename>typename> struct Templ2 {};

template<typename T>
struct Foo {
    //void foo(Foo<T> &) {
    // Foo ~ Foo<T>
    void foo(Foo &) {

    }

    void bar(Foo&);

    Foo baz1() {
        return {};
    }

    Foo baz2();

    void botva() {
        [[maybe_unused]] Templ1<Foo<T>> x;
        [[maybe_unused]] Templ1<Foo> z;
        [[maybe_unused]] Templ2<Foo> y;
    }
};

template<typename T>
void Foo<T>::bar(Foo &) {

}

template<typename T>
Foo<T> Foo<T>::baz2() {
}


int main() {
    Foo<int> x, y;
    x.foo(y);

    x.bar(y);

    x.botva();
} 