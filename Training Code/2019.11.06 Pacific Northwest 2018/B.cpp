#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e7 + 50;

int n;
bool p[N];
int mu[N], pm[N], pms;

void get_mobius_sieve() {
    mu[1] = 1;
    fill(p, p + N, true);
    pms = 0;
    for(int i = 2; i < N; i++) {
        if(p[i]) {
            pm[pms++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < pms && i * pm[j] < N; j++) {
            p[i * pm[j]] = false;
            if(i % pm[j] == 0) {
                mu[i * pm[j]] = 0;
                break;
            }
            mu[i * pm[j]] = -mu[i];
        }
    }
}

ll solve(int n, int m) {
    ll res = 0;
    for(int i = 1; i <= min(n, m); i++) {
        if(mu[i] == 0) continue;
        res += 1LL * mu[i] * (n / i) * (m / i);
    }
    return res;
}

int main() {
    get_mobius_sieve();
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ll res = solve(b, d) - solve(a - 1, d) - solve(b, c - 1) + solve(a - 1, c - 1);
    cout << res << endl;
}