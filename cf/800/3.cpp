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
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll &i : v) {
            cin >> i;
        }
        bool res = true; 
        vector<ll> p(n+1, 0);       
        for (size_t i = 1; i < p.size(); ++i) {
            p[i] = p[i-1] + v[i - 1];
        }

        if (p[n] != 0) 
            res = false;
        else {
            for (size_t i = 1; i < p.size(); ++i) {
                if (p[i] < 0)
                    res = false;
            }
            if (res) {
                bool b = false;
                for (size_t i = 1; i < p.size(); ++i) {
                    if (p[i] == 0)
                        b = true;
                    else if (b) {
                        res = false;
                    }
                }
            }
        }
        cout << (res ? "Yes" : "No") << '\n';
    }
}