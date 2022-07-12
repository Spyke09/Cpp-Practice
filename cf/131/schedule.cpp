#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
using ll = long long;

ll g(ll t, const vector<ll> &a) {
    ll sum = 0;
    ll n = a.size();
    for (ll i = 0; i < n; ++i) {
        ll t1 = min<ll>(t, a[i]);
        ll t2 = (t - t1) / 2;
        sum += t1 + t2;
    }
    return sum;
}
 
ll f(ll m, const vector<ll> &a) {
    ll r = 2*m, l = 0;
    
    while (l<r) {
        ll mid = (r - l)/2 + l;
        if (g(mid, a) >= m) r = mid;
        else l = mid+1;
    }
    return r;
}
 
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n, 0);
        for (ll i = 0; i < m; ++i) {
            ll tt;
            cin >> tt;
            a[tt-1]++;
        }
        cout << f(m, a) << '\n';
    }
    return 0;
}