template<typename T>
struct Foo {
    void foo();

    static int sf;
};

// void Foo::foo() {};

template<typename T>
void Foo<T>::foo() {};

template<typename T>
int Foo<T>::sf = 10;

int main() {
    Foo<int> x;
    x.foo();

    Foo<char>::sf = 10;
}