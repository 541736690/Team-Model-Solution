#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int dp[N];

int n;
vector<int> G[N];

void dfs(int v, int p) {
    int cnt = 0;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v);
        cnt += dp[nxt];
    }
    dp[v] = ((cnt+1) % 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);

    cout << (dp[0] ? "Alice" : "Bob") << endl;
}