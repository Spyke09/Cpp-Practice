template<typename T>
struct MyTemplate {
private:
    int x = 0;    
    friend void simple_func();
    // friend void non_simple_func(MyTemplate&);

    template<typename U>
    friend void foo(MyTemplate<U> &, MyTemplate<void> &);
};

void simple_func() {
    MyTemplate<int> val1;
    val1.x = 10;
}

// template<typename T>
// void non_simple_func(MyTemplate<T>& val) {
//     val.x = 10;
// }

template<typename U>
void foo(MyTemplate<U> &val, MyTemplate<void> &weird) {
    val.x = 10;
    weird.x = 10;
}

int main() {
    MyTemplate<int> val1;
    MyTemplate<char> val2;
    MyTemplate<void> weird;

    // void non_simple_func(MyTemplate<T>& val);
    foo(val1, weird);
    foo(val2, weird);
}