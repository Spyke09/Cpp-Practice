template<typename T>
struct Bar2;

template<typename T>
struct Foo {
private:
    int x = 0;

    template<typename /*U*/>
    friend struct Bar;
    friend struct Bar2<T>;
};

template<typename T>
struct Bar {
    void bar() {
        Foo<T> f;
        f.x = 10;

        Foo<void> g;
        g.x = 10;
    }
};

template<typename T>
struct Bar2 {
    void bar() {
        Foo<T> f;
        f.x = 10;

        Foo<void> g;
        //g.x = 10;
    }
};

int main() {
    Bar<int>().bar();
    Bar2<int>().bar();
}