#include <cassert>
#include <iostream>

template<typename T>
struct is_void {
    static inline const bool value = false;
};

template<>
struct is_void<void> {
    static inline const bool value = true;
};

template<typename T>
static const bool is_void_v =  is_void<T>::value;

int main() {
    std::cout << is_void_v<void> << "\n";
    std::cout << is_void_v<int> << "\n";
}
