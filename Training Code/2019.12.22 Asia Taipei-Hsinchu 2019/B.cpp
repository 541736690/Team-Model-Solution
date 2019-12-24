#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n;
vector<int> way[maxn];

int dp[maxn][5];

void solve(int u, int last) {

    int deg = 0;

    if(way[u].size() == 1) {
        dp[u][0] = dp[u][1] = 1;
        dp[u][2] = 0;
        // printf("dp %d = %d %d %d\n",u,dp[u][0],dp[u][1],dp[u][2]);
        return ;
    }

    for(auto v : way[u]) {
        if(v == last) continue;
        solve(v,u);
        deg++;
    }

    int sum0 = 0, sum1 = 0, sum2 = 0;
    int mn[5] = {0};

    for(auto v : way[u]) {
        sum0 += dp[v][0];
        sum1 += dp[v][1];
        sum2 += dp[v][2];
        mn[3] = min(mn[3], mn[2] - dp[v][0] + dp[v][2]); // from 0 to 2 and 0 to 1
        mn[3] = min(mn[3], mn[1] - dp[v][0] + dp[v][1]); // from 0 to 1 and 0 to 2
        mn[1] = min(mn[1], mn[0] - dp[v][0] + dp[v][2]); // from 0 to 2
        mn[2] = min(mn[2], mn[0] - dp[v][0] + dp[v][1]); // from 0 to 1
    }

    dp[u][0] = dp[u][1] = dp[u][2] = n;

    // 0: required

    if(deg >= 2) dp[u][0] = min(dp[u][0], sum0 + mn[3]);
    if(deg >= 1) dp[u][0] = min(dp[u][0], sum0);
    dp[u][0] = min(dp[u][0], 1 + sum2);

    // 1: required to be chosen OK

    dp[u][1] = min(dp[u][1], 1 + sum2);

    // 2: not required

    if(deg >= 2) dp[u][2] = min(dp[u][2], sum0 + mn[1]);
    dp[u][2] = min(dp[u][2], 1 + sum2);

    // printf("dp %d = %d %d %d\n",u,dp[u][0],dp[u][1],dp[u][2]);
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++) {
        int u,v; scanf("%d%d",&u,&v);
        way[u].push_back(v);
        way[v].push_back(u);
    }

    if(n == 2) return !printf("1");

    int root = 1;
    for(int u=1;u<=n;u++) if(way[u].size() > 1) root = u;

    solve(root,0);
    printf("%d",dp[root][2]);
}