#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define X first
#define Y second
const int maxn = 1e5 + 5;

int n;
vector<int> way[maxn];
int dp[maxn];
pii mx[maxn][2];
int ans;

void upd(int u, pii val) {
    for(int i=0;i<2;i++) if(mx[u][i] > val) swap(mx[u][i], val);
}

int get(int u, int ban) {
    for(int i=0;i<2;i++) if(mx[u][i].second != ban) return mx[u][i].first;
    return 1;
}

void dfs(int u, int last) {
    dp[u] = 1;
    for(auto v : way[u]) {
        if(v==last) continue;
        dfs(v,u);
        upd(u, {!dp[v], v});
    }
    dp[u] = get(u, 0);
    //printf("dp %d = %d\n",u,dp[u]);
}

void solve(int u, int last) {
    int res = min((int)!dp[last], get(u, 0));
    if(res) ans = 1;
    //printf("result %d = %d\n", u, res);
    for(auto v : way[u]) {
        if(v==last) continue;
        // change u
        dp[u] = min((int)!dp[last], get(u, v));
        // solve v
        solve(v, u);
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++) {
        int u,v; scanf("%d%d",&u,&v);
        way[u].push_back(v);
        way[v].push_back(u);
    }
    for(int i=1;i<=n;i++) mx[i][0] = mx[i][1] = {1, n+1};
    dfs(1,0);
    solve(1,0);
    if(ans) printf("Alice");
    else printf("Bob");
}