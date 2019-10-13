#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const int maxm = 1e6 + 5;

int n, m, q;
vector<int> way[maxn];

int h[maxn], par[maxn];
int sz[maxn], bigc[maxn];

int cnum, csz[maxn], cnxt[maxn];
int cid[maxn], cpos[maxn];
stack<pair<int,int>> wow[maxn];

int res[maxn], cnt[maxm];

void dfs(int u, int last) {
    h[u] = h[last] + 1;
    par[u] = last;

    sz[u] = 1;
    for(auto v : way[u]) {
        if (v == last) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[bigc[u]]) bigc[u] = v;
    }
}

void init(int u, int last) {
    cid[u] = cnum;
    cpos[u] = ++csz[cid[u]];
    if(cpos[u] == 1) cnxt[cid[u]] = par[u];

    if(bigc[u]) init(bigc[u], u);
    for(auto v : way[u]) {
        if(v == last || v == bigc[u]) continue;
        cnum++;
        init(v, u);
    }
}

void update(int x, int val) {
    //printf("update %d : %d\n",x,val);
    if(x == 0) return ;
    if(cnt[x] >= 0) res[cnt[x]]--;
    cnt[x] += val;
    if(cnt[x] >= 0) res[cnt[x]]++;
}

void hld_update(int u, int col) {
    while(u != 1) {
        int id = cid[u], pos = cpos[u];
        int last = 0;
        update(col, pos);
        while(!wow[id].empty()) {
            if(wow[id].top().second > pos) break;
            update(wow[id].top().first, -(wow[id].top().second - last));
            last = wow[id].top().second;
            wow[id].pop();
        }
        if(!wow[id].empty()) {
            update(wow[id].top().first, +(wow[id].top().second - pos));
            update(wow[id].top().first, -(wow[id].top().second - last));
        }
        wow[id].push({col, pos});
        u = cnxt[id];
    }
}

int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n-1;i++) {
        int u, v; scanf("%d%d",&u,&v);
        way[u].push_back(v);
        way[v].push_back(u);
    }

    dfs(1,0);
    for(auto u : way[1]) {
        cnum++;
        init(u,1);
    }

    res[0] = m;

    while(q--) {
        int u, col, want; scanf("%d%d%d",&u,&col,&want);
        hld_update(u, col);
        printf("%d\n",res[want]);
    }
}