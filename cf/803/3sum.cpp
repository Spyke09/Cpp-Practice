#include <unordered_set>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >>t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> rv(n);
        vector<int> v{};
        for (int &i : rv) {
            cin >> i;
        }
        int pos = 0, neg = 0;
        for (int i : rv) {
            pos += (i > 0);
            neg += (i < 0);
            if (i == 0 && static_cast<int>(v.size()) < 3) v.push_back(0);
        }
        if (pos > 2 || neg > 2) {
            cout << "NO" << '\n';
        } else {
            for (int i : rv) 
                if (i != 0) v.push_back(i);
            bool an = true;
            n = v.size();
            for (int i = 0; i < n && an; ++i) 
                for (int j = i + 1; j < n && an; ++j) 
                    for (int k = j + 1; k < n && an; ++k) {
                        if (find(v.begin(), v.end(), v[i] + v[j] + v[k]) == v.end()) an = false;
                    }
            cout << (an ? "YES" : "NO") << '\n';
        }
    }        
}