#include <cassert>
#include <iostream>
#include <utility>

struct Foo {
    int member_var = 10;
    static inline int static_member_var = 20;
    int arr[10'000];

    void method() {
        int local_var = 30;
        static int static_local_var = 40;

        // 1
        []() {
            // Not captured.
            // [[maybe_unused]] int x = member_var;
            // [[maybe_unused]] int y = local_var;
            // Never captured, always available
            static_member_var++;
            static_local_var++;
        }();
        assert(static_member_var == 21);
        assert(static_local_var == 41);

        // 2    
        std::cout << "before 2 " << &member_var << " " << &local_var << '\n';
        // здесь с помощью [=] будут копироваться все переменные класса и будут доступны в л-функции
        // если какая-то переменная не используется, то она не будет захватываться
        // можно проверить это, выведя размеры лямбд
        [=]() { // [this, local_var]
            std::cout << "in lambda 2 " << &member_var << " " << &local_var << '\n';
            assert(member_var == 10); // this->member_var: reference!
            assert(local_var == 30);
            // operator() is const by default.
            // member_var++;
            // local_var++;
        }();

        // 3
        auto lambda3 = [=]() mutable {
            // operator() is non-const now
            member_var++;
            local_var++;
        };
        lambda3();
        assert(member_var == 11);
        assert(local_var == 30);

        // 4
        [&]() {
            // operator() is still const, but it works
            member_var++;
            local_var++;
        }();
        assert(member_var == 12);
        assert(local_var == 31);
        
        // 5
        std::cout << "before 5 " << &member_var << " " << &local_var << '\n';
        auto lambda5 = [=, *this]() mutable {
            std::cout << "in lambda 5 " << &member_var << " " << &local_var << '\n';
            assert(member_var == 12);
            assert(local_var == 31);
            member_var++;
            local_var++;
        };
        lambda5();
        assert(member_var == 12);
        assert(local_var == 31);
        std::cout << "sizeof l5  " << sizeof(lambda5);

        // 6
        [wtf = local_var + member_var]() {
            assert(wtf == 43);
        }();
        
        [local_var = local_var * 2]() {
            assert(local_var == 62);
        }();
        assert(local_var == 31);
        [&local_var = local_var]() {
            assert(local_var == 31);
            local_var++;
        }();

        [&local_var = std::as_const(local_var)]() {
            assert(local_var == 32);
            // local_var++; // const int &local_var;
        }();
        assert(local_var == 32);
    }
};

int main() {
    static Foo foo;
    foo.method();
}