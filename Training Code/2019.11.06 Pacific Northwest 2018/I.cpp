#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
const int maxn = 2e5 + 5;

const ll inf = (ll)1e13;

struct Line {
    ll k, m;
    Line(ll _k, ll _m) {
        k = _k; m = _m;
    }
    Pll inter(Line o) {
        return {m-o.m, o.k-k};
    }
};

struct Hull {
    deque<Line> que;
    bool leq(Pll a, Pll b) {
        return a.first * b.second <= a.second * b.first;
    }
    void add(ll k, ll m) {
        while(que.size() > 1) {
            int ls = que.size() - 1;
            if(leq(que[ls].inter(Line(k,m)), que[ls-1].inter(que[ls]))) que.pop_back();
            else break;
        }
        que.push_back({k, m});
    }
    ll query_bin(ll x) {
        if(que.empty()) return -inf;
        int l = 0, r = que.size() - 1;
        while(l<r) {
            int mi = (l+r)/2;
            if(que[mi].k * x+ que[mi].m < que[mi+1].k * x + que[mi+1].m) l = mi+1;
            else r = mi;
        }
        return que[l].k * x + que[l].m;
    }
};

int n, m;
int a[maxn];

int cnt[105];

int sz;
int id[maxn];
int wow[maxn];
ll dp[maxn][2];

int main() {
    scanf("%d%d",&n,&m);
//    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    ll ans = 0;

    // initial
    for(int i=1;i<=n;i++) {
        if(a[i] != 0) {
            cnt[a[i]]++;
            for(int x=a[i]+1;x<=m;x++) ans += cnt[x];
        }
        else id[i] = ++sz;
    }

    /*// extra
    for(int x=1;x<=sz;x++) {
        for(int val=m;val>=1;val--) {
            dp[x][val] = dp[x][val+1];
            for(int y=0;y<x;y++) {
                dp[x][val] = max(dp[x][val], dp[y][val+1] - sum_wow[y][val] - y*y + x*y + sum_wow[x][val]);
            }
        }
    }*/

    for(int x=1;x<=sz;x++) dp[x][0] = dp[x][1] = -inf;

    for(int val=m;val>=1;val--) {
        for(int x=1;x<=sz;x++) wow[x] = 0;
        memset(cnt,0,sizeof(cnt));
        for(int x=1;x<=n;x++) {
            if(a[x] != 0) cnt[a[x]]++;
            else {
                for(int y=val+1;y<=m;y++) wow[id[x]] += cnt[y];
            }
        }
        memset(cnt,0,sizeof(cnt));
        for(int x=n;x>=1;x--) {
            if(a[x] != 0) cnt[a[x]]++;
            else {
                for(int y=val-1;y>=1;y--) wow[id[x]] += cnt[y];
            }
        }
        Hull hull;
        ll sum = 0;
        int t = val&1;
        for(int x=1;x<=sz;x++) {
            if(dp[x-1][!t] != -inf) hull.add(x-1, dp[x-1][!t] - sum - (ll)(x-1)*(x-1));
            sum += wow[x];
            ll qr = hull.query_bin(x);
            dp[x][t] = dp[x][!t];
            if(qr != -inf) dp[x][t] = max(dp[x][t], qr + sum);
        }
    }

    printf("%I64d",dp[sz][1] + ans);
}