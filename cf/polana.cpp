#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int sum = 0;
        for(int i = 0; i<4; i++) {
            int t;
            cin >> t;
            sum += (t == 1);
        }
        if (sum == 0) cout << 0;
        else if (sum < 4) cout << 1;
        else cout << 2;
        cout << '\n';
    }
}