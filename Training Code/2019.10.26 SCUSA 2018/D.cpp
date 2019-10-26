//
// Created by 54173 on 10/26/2019.
//

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define X first
#define Y second
const int infi = 1e9;
const ll inf = 1e15;
const int maxn = 2e5 + 5;

int n,m,q;
int dist[105][105];
vector<pair<pii,pii>> p;

int sz[maxn];
pair<int,ll> wow[105][maxn];

ll getmx(int x, int pos) {
    int l = 1, r = sz[x], mid;
    ll res = -inf;
    while(l<=r) {
        mid = (l+r)/2;
        if(wow[x][mid].X <= pos) {
            res = wow[x][mid].Y;
            l = mid+1;
        }
        else r = mid-1;
    }
    return res;
}

int main() {
    scanf("%d%d%d",&q,&n,&m);

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            dist[i][j] = (i==j ? 0 : infi);
        }
    }

    for(int i=1;i<=m;i++) {
        int u,v,val; scanf("%d%d%d",&u,&v,&val);
        dist[u][v] = min(dist[u][v], val);
        dist[v][u] = min(dist[v][u], val);
    }

    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1;i<=q;i++) {
        int u,s,e,val; scanf("%d%d%d%d",&u,&s,&e,&val);
        p.push_back({{e,s}, {u,val}});
    }

    sort(p.begin(),p.end());

    ll ans = 0;
    wow[1][++sz[1]] = {0, 0};
    for(auto tmp : p) {
        int u = tmp.Y.X, s = tmp.X.Y, e = tmp.X.X, val = tmp.Y.Y;
        ll mx = -inf;
        for(int v=1;v<=n;v++) {
            mx = max(mx, getmx(v, s-dist[u][v]));
        }
        mx += val;
        if(sz[u]==0 || wow[u][sz[u]].Y < mx) wow[u][++sz[u]] = {e, mx};
        ans = max(ans, mx);
    }
    printf("%lld",ans);
}