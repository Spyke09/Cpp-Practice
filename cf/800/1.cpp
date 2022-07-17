#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        char c = a > b ? '0' : '1';
        for (int i = 0; i < min(a, b); ++i)
            cout << "01";
        for (int i = 0; i < abs(a - b); ++i)
            cout << c;
        cout << '\n';
    }
}