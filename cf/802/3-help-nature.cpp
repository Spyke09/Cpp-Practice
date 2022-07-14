#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;


void f(int n) {
    vector<ll> v(n);
    ll res = 0;
    for (ll &i : v) {
        cin >> i;
    }

    ll v0 = v[0];
    for (int i = 0; i < n - 1; i++) {
        int t = v[i + 1] - v[i];
        res += abs(t);
        if(t < 0)
             v0 += t;
    }
    res += abs(v0);
    cout << res << '\n';
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        f(n);
    }
}