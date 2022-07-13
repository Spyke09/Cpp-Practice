#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int sum = 0, a1, a2, a3;
        cin >> a1 >> a2;
        for (int i = 2; i < n; ++i) {
            cin >> a3;
            if (a1 + a3 < a2) {
                sum++;
            }
            a1 = a2;
            a2 = a3;
        }
        if (k == 1) {
            cout << (n - 1) / 2;
        } else {
            cout << sum;
        }
        cout << '\n';
    }
}