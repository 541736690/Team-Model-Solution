#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e4 + 50, K = 1005, mod = (int)1e9 + 7;

int n, m;
int a[N], b[N];
int f[N][K], g[N][K];

inline void inc(int &a, int b) {
    a += b;
    if(a >= mod) a -= mod;
}

void add(int *dp, int x) {
    for(int i = 0; i + x < K; i++) inc(dp[i + x], dp[i]);
}

void del(int *dp, int x) {
    for(int i = K - 1; i >= x; i--) inc(dp[i], mod - dp[i - x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas++) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
            a[i] = (a[i] + 1) * b[i];
        }
        for(int j = 0; j < K; j++) {
            f[0][j] = (j == 0);
            g[0][j] = (j == 0);
        }
        for(int i = 1; i <= n; i++) {
            memcpy(f[i], f[i-1], sizeof(f[i]));
            add(f[i], b[i]);
            del(f[i], a[i]);
            memcpy(g[i], g[i-1], sizeof(g[i]));
            add(g[i], a[i]);
            del(g[i], b[i]);
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < K; j++) inc(f[i][j], f[i][j-1]);
        }

        cout << "Case #" << cas << ":\n";
        int ans = 0;
        for(int i = 0; i < m; i++) {
            int l, r, c; cin >> l >> r >> c;
            l = (l + ans) % n + 1;
            r = (r + ans) % n + 1;
            if(l > r) swap(l, r);
            ans = 0;
            for(int j = 0; j <= c; j++) inc(ans, (int)(1LL * f[r][j] * g[l-1][c-j] % mod));
            cout << ans << '\n';
        }
    }
}