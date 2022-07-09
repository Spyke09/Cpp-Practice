#include <iostream>
#include <vector>

int main() {
    //переменные умирают внутри фигурных скобок
    [[maybe_unused]]int x;
    {
        [[maybe_unused]] std::vector<int> v(10);
        for (int i = 0; i<10; x++) {
            [[maybe_unused]] std::vector<int> d(10);
        }
    }
    [[maybe_unused]] int data[100];
}