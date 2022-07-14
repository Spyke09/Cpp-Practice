#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        char chr;
        cin.get(chr);
        for (int &i : v) {
            cin.get(chr);
            i = static_cast<int>(chr) - 48;
        }
        if (v[0] != 9) {
            for (int i = 0; i < n; ++i) {
                cout << 9 - v[i];
            }
        } else {
            int z = 1;
            for (int i = n - 1; i >= 0; --i) {
                if (z - v[i] < 0) {
                    v[i] =  10 + z - v[i];
                    z = 0;
                } else {
                    v[i] =  z - v[i];
                    z = 1;
                }
            }
            for (int i : v) {
                cout << i;
            }
        }
        cout << '\n';
    }
}