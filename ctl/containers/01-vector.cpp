#include <vector>
#include <iostream>

int main() {
    // конструктор по умолчанию O(1)
    std::vector<int> v;

    // Вставка в конец O(1)
    v.push_back(1);
    v.push_back(2);

    // доступ к элементам O(1)
    std::cout << "v[0] :" << v[0] << '\n';
    // выдаст ошибку, если обраться за границы массива в отличие от []
    // но at() работает медленнее
    std::cout << "v[0] :" << v.at(0) << '\n';

    // удаление с конца O(1)
    v.pop_back();
    std::cout << "v[0] after pop:" << v[0] << '\n';

    std::cout << "Size: " << v.size() << '\n';
    v.clear();
    std::cout << "Size after clean: " << v.size() << '\n';


    v = {1, 2, 3, 4};
    v.push_back(5);
    for (int i : v) 
        std::cout << i << '\n';

    std::cout << "Capacity: " << v.capacity() << '\n';

    // устаначливаем capacity равным 100, т.е. зараннее резервируем O(1)
    v.reserve(100);
    std::cout << "Capacity: " << v.capacity() << '\n';
    v.shrink_to_fit();
    std::cout << "Capacity: " << v.capacity() << '\n';

    // инициализация  за O(n)
    v = std::vector<int>(20, -1);
    // empty() O(1)
    std::cout << "Empty: " << v.empty() << '\n';
    
    // resize() O(1)
    std::cout << "Size: " << v.size() << '\n';
    v.resize(22);
    std::cout << "Size: " << v.size() << '\n';

    // еще insert() и erase()
    
}