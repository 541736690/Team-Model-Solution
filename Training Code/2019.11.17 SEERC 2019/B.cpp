#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 505;
const ll INF = (ll)1e18;

struct Item {
    int x, t, y, r;

    void read() {
        cin >> x >> t >> y >> r;
    }
} it[N];

int n, s1, s2;
ll dp[2][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s1 >> s2;
    for(int i = 0; i < n; i++) it[i].read();
    sort(it, it + n, [](const Item &i1, const Item &i2) {
        return i1.x < i2.x;
    });
    int nw = 0, la = 1;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) dp[0][i][j] = dp[1][i][j] = INF;
    dp[nw][s1][s2] = 0;
    for(int i = 0; i < n; i++) {
        swap(nw, la);
        for(int k = 0; k < N; k++) for(int j = 0; j < N; j++) dp[nw][k][j] = INF;
        for(int j1 = 0; j1 <= s1; j1++) {
            for(int j2 = 0; j2 <= s2; j2++) {
                if(dp[la][j1][j2] == INF) continue;
                if(j1 >= it[i].x) {
                    dp[nw][j1 - it[i].x][j2] = min(dp[nw][j1 - it[i].x][j2], dp[la][j1][j2] + it[i].t);
                }
                if(j1 != 0 && j1 < it[i].x) {
                    int nj2 = max(0, j2 - (it[i].x - j1));
                    dp[nw][0][nj2] = min(dp[nw][0][nj2], dp[la][j1][j2] + it[i].t);
                }
                dp[nw][j1][max(0, j2 - it[i].y)]
                    = min(dp[nw][j1][max(0, j2 - it[i].y)], dp[la][j1][j2] + it[i].r);
                dp[nw][j1][j2] = min(dp[nw][j1][j2], dp[la][j1][j2]);
            }
        }
    }
    if(dp[nw][0][0] == INF) dp[nw][0][0] = -1;
    cout << dp[nw][0][0] << endl;
}