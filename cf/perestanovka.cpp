#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> range(int n) {
    vector<int> a(n);
    for (int i = 0; i<n; i++) {
        a[i] = i + 1;
    }
    return a;
}

int cost(vector<int> a, int d) {
    int sum = 0;
    for (int i = 0; i < static_cast<int>(a.size()) - 1; ++i) {
        if (a[i] * d == a[i+1]) sum++;
    }
    return sum;
}

vector<int> optimal_p(int n) {
    vector<int> a = range(n);
    vector<int> res;
    int opt = 0;
    do {
        for (int d = 1; d<n+1; ++d) {
            int cur = cost(a, d);
            if (cur > opt) {
                opt = cur;
                res = a;
            }
        }
    } while(next_permutation(a.begin(), a.end()));
    return res;
}

vector<int> optimal_p2(int n) {
    vector<int> a(n);
    vector<bool> check(n+1, false);
    int k = 1;
    int j = 0;
    while(k <= n) {
        if (!check[k]) {
            int t = k;
            while(t <= n) {
                check[t] = true;
                a[j++] = t;
                t *= 2;
            }
        }
        k++;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a = optimal_p2(n);
        cout << 2 << '\n';
        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << '\n';
    }
}