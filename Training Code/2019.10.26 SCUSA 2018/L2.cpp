//
// Created by 54173 on 10/26/2019.
//
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 5e4 + 5;
const ll inf = 2e18;

int n, m;
ll val[maxn];
int good[maxn];
multiset<ll> have[2];
vector<int> way[maxn];

ll calc(int x, ll val) {
    if(have[x].empty()) return inf;

    auto R = have[x].lower_bound(val);
    auto L = R; L--;

    ll res = inf;
    if(R != have[x].begin()) {
        ll tmp = *L;
        res = min(res, (ll)abs(val*val*val - tmp*tmp*tmp));
    }
    if(R != have[x].end()) {
        ll tmp = *R;
        res = min(res, (ll)abs(val*val*val - tmp*tmp*tmp));
    }

    return res;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        char type; scanf("%lld %c",&val[i],&type);
        if(type == 'a') good[i] = 1;
        have[good[i]].insert(val[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++) {
        int u,v; scanf("%d%d",&u,&v);
        way[u].push_back(v);
        way[v].push_back(u);
    }

    ll ans = inf;

    // no device
    for(int u=1;u<=n;u++) {
        ans = min(ans, calc(!good[u], val[u]));
    }

    // use device
    for(int u=1;u<=n;u++) {
        // match with incident
        for(auto v : way[u]) {
            if(good[u] != good[v]) {
                ll x = val[u] - 1;
                ll y = val[v] + 1;
                ans = min(ans, (ll)abs(x*x*x - y*y*y));
            }
        }

        // incident matching
        for(auto x : way[u]) {
            for(auto y : way[u]) {
                if(good[x] == good[y]) continue;
                ll xx = val[x] + 1;
                ll yy = val[y] + 1;
                ans = min(ans, (ll)abs(xx*xx*xx - yy*yy*yy));
            }
        }

        // remove incidents
        for(auto v : way[u]) {
            have[good[v]].erase(have[good[v]].find(val[v]));
        }

        // remove itself
        have[good[u]].erase(have[good[u]].find(val[u]));

        // match with non-incidents
        ans = min(ans, calc(!good[u], val[u] - 1));

        // incident match with non-incidents
        for(auto v : way[u]) {
            ans = min(ans, calc(!good[v], val[v] + 1));
        }

        // add incidents
        for(auto v : way[u]) {
            have[good[v]].insert(val[v]);
        }

        // add itself
        have[good[u]].insert(val[u]);
    }

    printf("%lld",ans);
}