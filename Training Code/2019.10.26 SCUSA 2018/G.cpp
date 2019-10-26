#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        ll res = 1;
        for(int i = 1; i <= n; i++) res *= i;
        cout << res % 10 << endl;
    }
}