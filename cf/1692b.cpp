#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> read(int n)
{
    unordered_map<int, int> a;
    for (int i = 0; i<n; ++i) {
        int c;
        cin>>c;
        if (a.find(c)==a.end()) {
            a[c] = 1;
        } else {
            a[c]++;
        }
    }
    return a;
}

int f(unordered_map<int, int> a)
{
    int c = 0;
    for (auto &p: a)
        if (p.second % 2 == 0) c++;
    
    if (c%2 == 0) return a.size();
    else return a.size()-1; 

}

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i<n; ++i) {
        int k;
        cin>>k;
        cout<<f(read(k))<<endl;
    }
    return 0;
}