#include <vector>
#include <cassert>

void readWord(char* buf) {
}

int counter() {
    static int c = 0;
    return ++c;
}

void foo(int n) {
    static std::vector<int> v(n);
    static const int x = n;
    assert(static_cast<int>(v.size()) == n);
}

int main() {
    // здесь переменная будет лежать в глобабьной памяти, а не на стеке, что лучше
    for (int i = 0; i<100; ++i) {
        static char buf[100'000'000];
        readWord(buf);
    }
    foo(10);
    foo(11);
}