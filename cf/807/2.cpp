#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> v(n);
        
        for (auto& i : v) {
            cin >> i;
        }
        int i0 = 0;
        while(v[i0] == 0) i0++;
        ll zero = 0, sum = 0;
        for (int i = i0; i < n - 1; ++i) {
            if (v[i] == 0) {
                zero++;
            }
            sum += v[i];
        }
        cout << sum + zero << '\n';
    }
}