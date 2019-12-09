#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)6e7;

ll qs[N], qn[N], qlen = 0;

ll solve(ll n, ll m, ll k) {
    ll nxt = 0;
    qlen = 0;
    while(true) {
        ll steps = (n + k - 1) / k;
        if(m <= steps) {
            nxt = (m * k - 1) % n;
            break;
        }

        qn[qlen] = n;
        qs[qlen++] = steps;
        n -= steps, m -= steps;
    }
    while(qlen > 0) {
        qlen--;
        ll cn = qn[qlen], csteps = qs[qlen];
        ll start = (csteps * k) % cn;
        if(start + nxt < k - 1) {
            nxt = (start + nxt) % cn;
            continue;
        }
        ll rem = (start + nxt - (k - 1));
        nxt = (k + rem / (k - 1) * k + rem % (k - 1)) % cn;
    }
    return nxt;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        ll n, m, k;
        cin >> n >> m >> k;
        ll res;
        if(k == 1) res = m - 1;
        else res = solve(n, m, k);
        cout << "Case #" << t << ": " << res + 1 << '\n';
    }
}