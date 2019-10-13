#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, int> mp;
int tcnt = 0;
ll val[130];
int res[2][130];
ll sz[130];

int get_idx(ll x) {
    if(mp.count(x)) return mp[x];
    val[tcnt] = x;
    return mp[x] = tcnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        ll n;
        cin >> n;
        mp.clear();
        tcnt = 0;
        priority_queue<ll> que;
        que.push(n);
        get_idx(n);
        while(!que.empty()) {
            ll v = que.top(); que.pop();
            if(v == 1) {
                res[0][get_idx(v)] = res[1][get_idx(v)] = -1;
                continue;
            }
            if(!mp.count(v - v / 2)) {
                que.push(v - v / 2);
            }
            res[0][get_idx(v)] = get_idx(v - v / 2);

            if(!mp.count(v / 2)) {
                que.push(v / 2);
            }
            res[1][get_idx(v)] = get_idx(v / 2);
        }
        cout << tcnt << "\n";
        reverse(res[0], res[0] + tcnt);
        reverse(res[1], res[1] + tcnt);
        reverse(val, val + tcnt);
        for(int i = 0; i < tcnt; i++) {
            if(res[0][i] != -1) {
                res[0][i] = tcnt - 1 - res[0][i];
                res[1][i] = tcnt - 1 - res[1][i];
                sz[i] = sz[res[1][i]] + sz[res[0][i]];
            }
            else {
                sz[i] = 1;
            }
            assert(res[0][i] <= i - 1 && res[1][i] <= i - 1);
            cout << res[0][i] << " " << res[1][i] << '\n';
        }
//        cout << sz[tcnt-1] << '\n';
//        assert(sz[tcnt-1] == n);
        cout << tcnt - 1 << '\n';
    }
}