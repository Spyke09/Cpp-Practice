#include <vector>

using vi1 = std::vector<int>;
typedef std::vector<int> vi2;

template<typename T>
using v = std::vector<T>;

int main() {
    v<int> v; 
}