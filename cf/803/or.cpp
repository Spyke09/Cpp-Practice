#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int& i : v) cin >> i;
        for (int i = 0; i < n; ++i) {
            int sum = i == 0 ? v[1] : v[0];
            for (int j = i == 0 ? 2 : 1; j < n; ++j) {
                if (i != j) {
                    sum ^= v[j];
                }
            }
            if (sum == v[i]) {
                cout << sum << '\n';
                break;
            }
        }
        
    }
}