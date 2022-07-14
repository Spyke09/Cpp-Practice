#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        cout << (m - 1) * m / 2 + m * n * (n + 1)/2 << '\n';
    }
}