#include <bits/stdc++.h>
using namespace std;

const int N = 250005, K = 10;
typedef long long ll;
const ll INF = (ll)1e18;

ll dp[2][K * 2 + 1][K + 1][3];

int n, k;
int w[N];

void umin(ll &to, ll val) {
    to = min(to, val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> w[i];

    int nw = 0, la = 1;
    memset(dp, 0x3f, sizeof(dp));

    dp[0][10][0][1] = 0;
    for(int i = 0; i < n; i++) {
        swap(nw, la);
        memset(dp[nw], 0x3f, sizeof(dp[nw]));
        for(int net = 0; net < 2 * K; net++) {
            for(int tot = 0; tot < K; tot++) {
                umin(dp[nw][net][tot][0], dp[la][net+1][tot][0]);
                umin(dp[nw][net][tot][0], dp[la][net+1][tot][1]);
                umin(dp[nw][net][tot][0], dp[la][net+1][tot][2]);
                umin(dp[nw][net][tot][0], dp[la][net][tot][0] + w[i]);
                umin(dp[nw][net][tot][0], dp[la][net][tot][1] + w[i]);
                umin(dp[nw][net][tot][0], dp[la][net][tot][2] + w[i]);

                if(net - 1 >= 0 && tot >= 1) umin(dp[nw][net][tot][1], dp[la][net - 1][tot - 1][0] + w[i]);
                umin(dp[nw][net][tot][1], dp[la][net][tot][0]);

                if(net - 1 >= 0 && tot >= 1) umin(dp[nw][net][tot][2], dp[la][net - 1][tot - 1][1] + w[i]);
                umin(dp[nw][net][tot][2], dp[la][net][tot][1]);
            }
        }
    }
    ll res = INF;
    for(int tot = 0; tot <= k; tot++) {
        umin(res, dp[nw][10][tot][0]);
        umin(res, dp[nw][10][tot][1]);
    }
    cout << res << '\n';
}