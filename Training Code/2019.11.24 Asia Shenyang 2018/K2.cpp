#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 50;

ll solve_brute(ll n, ll m, ll k) {
    if(m == 1) return (k - 1) % n;
    return (solve_brute(n - 1, m - 1, k) + k) % n;
}

ll solve_smart(ll n, ll m, ll k) {
    if(k == 1) return m - 1;

    ll steps = (n + k - 1) / k;
//    assert(m != 0);
    if(m <= steps) return (m * k - 1) % n;

    ll nxt = solve_smart(n - steps, m - steps, k);

    ll start = (steps * k) % n;

    if(start + nxt < k - 1) return (start + nxt) % n;
    ll rem = (start + nxt - (k - 1));
    cout << steps << endl;
    cout << start << " " << nxt << endl;
    return (k + rem / (k - 1) * k + rem % (k - 1)) % n;
}

bool in[N];

void check() {
    ll n, k;
    while(cin >> n >> k) {
        fill(in, in + n + 1, false);
        for(int m = 1; m <= n; m++) {
            ll s = solve_smart(n, m, k);
            cout << m << ": " << s << endl;
            assert(solve_brute(n, m, k) == s);
            in[s] = true;
        }
        for(int i = 0; i < n; i++) {
            assert(in[i]);
        }
        cout << "Good" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);


    check();
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        ll n, m, k;
        cin >> n >> m >> k;
//        assert(solve_smart(n, m, k) == solve_brute(n, m, k));
        cout << "Case #" << t << ": " << solve_smart(n, m, k) + 1 << '\n';
    }
}