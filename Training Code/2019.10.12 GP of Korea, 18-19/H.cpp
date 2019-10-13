#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//ll a, b, c, d;

ll solve(ll a, ll b) {
    ll res = 0;
    for(int i = 1; i < 1000; i++) {
        for(int j = 1; j + i < 1000; j++) {
            if(__gcd(i, j) != 1) continue;
            res += min(a / i, b / j);
        }
    }
    return res;
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << solve(b, d) - solve(a - 1, d) - solve(b, c - 1) + solve(a - 1, c - 1) << endl;
}