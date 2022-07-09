#include <iostream>

using namespace std;

void f(int n) {
    if  (n == 1) cout << -1;
    else if (n%2 == 0) {
        n /= 2;
        cout << 0 << ' ' << n << ' ' << n;
    } else {
        cout << -1;
    }
    cout<<"\n";
}

int main() {
    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        f(n);
    }
    return 0;
}