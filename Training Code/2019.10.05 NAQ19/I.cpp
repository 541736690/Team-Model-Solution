#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 500 + 5;
const ll inf = 1e15;

int n,m,k;
ll wow;
int good[maxn];
ll dis[maxn][maxn];
vector<pair<int,ll>> way[maxn];
ll ans[maxn];
priority_queue<pair<ll,int>> heap;

int main() {
    scanf("%d%d%d%lld",&n,&m,&k,&wow);
    good[1] = good[n] = 1;
    for(int i=1;i<=k;i++) {
        int x; scanf("%d",&x);
        good[x] = 1;
    }
    for(int u=1;u<=n;u++) for(int v=1;v<=n;v++) dis[u][v] = inf;
    for(int i=1;i<=m;i++) {
        int u,v; ll val; scanf("%d%d%lld",&u,&v,&val);
        dis[u][v] = min(dis[u][v], val);
        dis[v][u] = min(dis[v][u], val);
    }
    for(int k=1;k<=n;k++) {
        for(int u=1;u<=n;u++) {
            for(int v=1;v<=n;v++) {
                dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }
    for(int u=1;u<=n;u++) {
        if(!good[u]) continue;
        for(int v=1;v<=n;v++) {
            if(!good[v]) continue;
            if(dis[u][v]<=wow) {
                way[u].push_back({v,dis[u][v]});
            }
        }
    }
    for(int u=1;u<=n;u++) ans[u] = inf;
    ans[1] = 0;
    heap.push({0,1});
    while(!heap.empty()) {
        auto tmp = heap.top(); heap.pop();
        int u = tmp.second; ll val = -tmp.first;
        if(ans[u] != val) continue;
        for(auto nxt : way[u]) {
            int v = nxt.first; ll len = nxt.second;
            if(ans[v] > ans[u] + len) {
                ans[v] = ans[u] + len;
                heap.push({-ans[v], v});
            }
        }
    }
    if(ans[n] == inf) printf("stuck");
    else printf("%lld",ans[n]);
}