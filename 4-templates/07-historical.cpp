#include <vector>

int main() {
    //не скомпилируется в C++03
    //>> - только побитвый сдвиг
    std::vector<std::vector<int>> v;
    //скомпилируется в C++03
    std::vector<std::vector<int> > v;
}