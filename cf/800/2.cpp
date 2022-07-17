#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

template<typename T>
void printColection(const T &l) {
    for (const auto &i : l) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<int> v(n);
        char c;
        cin.get(c);
        for (int &i : v) {
            cin.get(c);
            i = c=='0' ? 0 : 1;
        }
        ll res = n;
        for (size_t i = 1; i < v.size(); ++i) {
            if (v[i] != v[i - 1])
                res += i;
        }
        cout << res << '\n';
    }
}