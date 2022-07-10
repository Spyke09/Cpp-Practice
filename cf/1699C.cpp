#include <iostream>

using ll = long long;
using namespace std;


void f() {
    static const ll mod = 1e9 + 7, nmax = 10e5;
    static ll pos[nmax]; 
    ll l, r, n, res = 1;
    cin >> n;
    for (int i = 0; i<n; i++) {
        ll buff;
        cin >> buff;
        pos[buff] = i;
    }

    l = r = pos[0];
    for (int i = 1; i<n; ++i) {
        if (pos[i] > r) r = pos[i];
        else if (pos[i] < l) l = pos[i];
        else res *= (r - l + 1 - i);
        res%=mod;
        // cout << l << ' ' << pos[i] << ' ' << r << ' ' << (r - l + 1 - i) << '\n';
    }
    cout << res << '\n';
}

int main() {
    ll n;
    cin >> n;
    
    while(n--) f();
    return 0;
}