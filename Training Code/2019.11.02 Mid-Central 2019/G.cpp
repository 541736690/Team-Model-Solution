#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define X first
#define Y second
const int maxn = 1000 + 5;
const int inf = 1e9;

int n, m, k, sz;
vector<pii> way[maxn];
vector<int> have[maxn];

int id[maxn], wow[maxn];
int dp[maxn][150];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
    int u,bit,val;
    node(int _u = 0, int _bit = 0, int _val = 0) {
        u = _u; bit = _bit; val = _val;
    }
    bool operator < (node a) const {
        return a.val < val;
    }
};

bool gen() {
    int check = 0;
    for(int i=1;i<=sz;i++) {
        wow[i] = rng() % 7;
        check |= (1<<wow[i]);
        //printf("wow %d = %d\n",i,wow[i]);
    }
    if(check != (1<<7)-1) return 0;
    /*for(int i=1;i<=sz;i++) {
        printf("wow %d = %d\n",i,wow[i]);
    }*/
    //printf("-------\n");
    for(int x=1;x<=n;x++) {
        id[x] = 0;
        for(auto i : have[x]) {
            //printf("\t\ti = %d\n", i);
            id[x] |= (1 << wow[i]);
        }
        //printf("\tid %d = %d\n",x,id[x]);
    }
    return 1;
}

int f(int u, int bit) {
    if(bit == (1<<7) - 1) return 0;

    if(dp[u][bit] == -1) {
        dp[u][bit] = inf;
        int res = inf;
        for(auto tmp : way[u]) {
            int v = tmp.X, val = tmp.Y;
            res = min(res, f(v,bit|id[v]) + val);
        }
        dp[u][bit] = res;
        //if(dp[u][bit]!=inf) printf("\tdp %d %d = %d\n",u,bit,dp[u][bit]);
    }
    return dp[u][bit];
}

int solve() {
    int mx = (1<<7) - 1;
    priority_queue<node> heap;
    for(int i=1;i<=n;i++) for(int bit=0;bit<=mx;bit++) dp[i][bit] = inf;
    dp[1][id[1]] = 0;
    heap.push(node(1, id[1], dp[1][id[1]]));
    while(!heap.empty()) {
        auto tmp = heap.top(); heap.pop();
        int u = tmp.u, bit = tmp.bit;
        if(tmp.val != dp[u][bit]) continue;
        if(bit == mx) return tmp.val;
        for(auto nxt : way[u]) {
            int v = nxt.X, val = nxt.Y;
            if(dp[v][bit | id[v]] > dp[u][bit] + val) {
                dp[v][bit | id[v]] = dp[u][bit] + val;
                heap.push(node(v,bit|id[v],dp[v][bit|id[v]]));
            }
        }
    }
    return inf;
}

void cpidx() {
    map<int,int> mp;
    for(int u=1;u<=n;u++) for(auto val : have[u]) mp[val];
    for(auto &t : mp) t.second = ++sz;
    for(int u=1;u<=n;u++) for(auto &val : have[u]) val = mp[val];
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) {
        int u,v,val; scanf("%d%d%d",&u,&v,&val);
        way[u].push_back({v,val});
        way[v].push_back({u,val});
    }
    for(int i=1;i<=k;i++) {
        int u,val; scanf("%d%d",&u,&val);
        have[u].push_back(val);
    }
    cpidx();

    int ans = inf;
    int round = 0;
    while((long double)clock()/CLOCKS_PER_SEC <= 15.0) {
        //printf("ROUND %d\n",round);
        if(!gen()) continue;
        ans = min(ans, solve());
        //printf("\n\n");
    }
    if(ans != inf) printf("%d",ans);
    else printf("-1");
}