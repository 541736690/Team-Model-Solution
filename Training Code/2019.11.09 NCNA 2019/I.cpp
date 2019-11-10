#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 3e5 + 5;

int n;
ll a[maxn];
ll DD, TT;
ll sz[maxn], sum[maxn];
ll ans[maxn];
vector<pair<int,ll>> way[maxn];

void dfs(int u, int last, ll len) {
    DD += len;
    TT += len*a[u];
    sz[u] = 1;
    sum[u] = a[u];
    for(auto tmp : way[u]) {
        int v = tmp.first; ll val = tmp.second;
        if(v==last) continue;
        dfs(v,u,len+val);
        sz[u] += sz[v];
        sum[u] += sum[v];
    }
}
void solve(int u, int last, ll D, ll T) {
    ans[u] = D * a[u] + T;
    for(auto tmp : way[u]) {
        int v = tmp.first; ll val = tmp.second;
        if(v==last) continue;
        solve(v,u,D - val*sz[v] + val*(n-sz[v]), T - val*sum[v] + val*(sum[1]-sum[v]));
    }
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n-1;i++) {
        int u,v; ll val; scanf("%d%d%lld",&u,&v,&val);
        way[u].push_back({v,val});
        way[v].push_back({u,val});
    }
    dfs(1,0,0);
    solve(1,0,DD,TT);
    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
}