#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, x;
        cin >> n >> x;
        vector<ll> v(2 * n);
        for (auto& i : v) {
            cin >> i;
        }
        sort(v.begin(), v.end());
        bool ans = true;
        for (int i = 0; i < n; ++i) {
            if (v[i + n] < v[i] + x) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
}