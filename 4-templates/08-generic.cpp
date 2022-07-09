template<typename T>
struct foo {
    int y;

    void bar() {
        //T::* y; - здесь будет как умножение
        typename T::x *y; //здесь все впорядке
    }
};

int main(){
    
}