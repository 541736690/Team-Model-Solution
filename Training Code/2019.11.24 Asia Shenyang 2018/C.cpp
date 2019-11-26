#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, mod;

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> n >> k >> mod;
        k = min(k, n);
        ll res = 1;
        for(int i = 1; i <= k; i++) res = (res * i) % mod;
        res = (res * ((n - k) * (n - 1) + 1)) % mod;
        cout << "Case #" << t << ": " << res << '\n';
    }
}