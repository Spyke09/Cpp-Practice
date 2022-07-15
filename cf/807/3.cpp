#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct mpair {
    long long r, l, len;
};

int bin_s2(vector<mpair> v, ll key) {
    [[maybe_unused]]int r = v.size() - 1, l = 0;
    while (l < r) {
        int mid = (r + l) / 2;
        if (v[mid].len > key) r = mid;
        else l = mid + 1;
    }

    return l;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, c, q;
        cin >> n >> c >> q;
        vector<char> s(n);
        vector<mpair> p(c + 1);
        ll len = s.size();
        for (auto& i : s) {
            cin >> i;
        }

        p[0].l = 0;
        p[0].r = len - 1;
        p[0].len = len;
        for (int i = 1; i < c + 1; ++i) {
            cin >> p[i].l >> p[i].r;
            p[i].l--;
            p[i].r--;
            p[i].len = p[i - 1].len + (p[i].r - p[i].l + 1);
        }
        while(q--) {
            int j;
            cin >> j;
            j--;
            while(j >= len) {
                int ind = bin_s2(p, j);
                int dist = p[ind].len - j - 1;
                j = p[ind].r - dist;
            }
            cout << s[j] << '\n';
        }
        cout << '\n';
    }
}