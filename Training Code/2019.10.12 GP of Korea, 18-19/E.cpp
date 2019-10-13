#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n, m;
vector<int> way[maxn];
int h[maxn], vis[maxn];
vector<int> good[maxn];
vector<int> bad[maxn];
int fen[maxn];
int ans;
set<pair<int,int>> have;

void add(int x, int val) {
    while(x <= n) {
        fen[x] += val;
        x += x&-x;
    }
}

int sum(int x) {
    int res = 0;
    while(x) {
        res += fen[x];
        x -= x&-x;
    }
    return res;
}

void dfs(int u, int last) {
    h[u] = h[last] + 1;
    vis[u] = 1;
    for(auto v : way[u]) {
        if(!vis[v]) {
            dfs(v,u);
            good[u].push_back(v);
        }
        else if(h[v] < h[u]) bad[u].push_back(v);//, printf("bad %d %d\n",u,v);
    }
}

void solve(int u, int last) {
    //check
    for(auto v : bad[u]) {
        if(sum(h[u]) - sum(h[v]-1) != 0) ans = 0;
    }
    //update
    for(auto v : bad[u]) {
        add(h[v],-1);
        add(h[u]-1,1);
    }
    //recur
    for(auto v : good[u]) {
        solve(v,u);
    }
    //update
    for(auto v : bad[u]) {
        add(h[v],1);
        add(h[u]-1,-1);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int u,v; scanf("%d%d",&u,&v);
        if(u>v) swap(u,v);
        if(have.find({u,v})!=have.end()) continue;
        way[u].push_back(v);
        way[v].push_back(u);
        have.insert({u,v});
    }

    vis[0] = 1;
    dfs(1,0);

    ans = 1;
    solve(1,0);
    if(ans) printf("Yes");
    else printf("No");
}