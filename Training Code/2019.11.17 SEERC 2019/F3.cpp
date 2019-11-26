#include<bits/stdc++.h>
using namespace std;

void dfs(int u, int last) {
    for(auto v : way[u]) {
        if(v==last) continue;
        has[u][0] += has[v][0];
        has[u][1] += has[v][1];
    }
    if(has[u][0]>=2) {
        dp[u] = 1;
        has[u][0] -= 2;
    }
    else if(has[u][1] >= 2) {
        dp[u] = 1;
        has[u][1] -= 2;
    }
    else if(has[u][0]==1) {
        dp[u] = 1;
        has[u][0] -= 2;
    }
    else dp[u] = 0;

    dp[u]
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++) {
        int u,v; scanf("%d%d",&u,&v);
        way[u].push_back(v);
        way[v].push_back(u);
    }
    dfs(1,0);
}