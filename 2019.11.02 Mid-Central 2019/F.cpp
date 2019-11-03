#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll, int> P;
const int N = (int)2e5 + 50;
const ll INF = (ll)1e18;

struct edge {
    int to, cost;
    edge(int _to, int _cost) {
        to = _to;
        cost = _cost;
    }
};

vector<edge> G[N];
ll dis[N];

void dijkstra(int s) {
    fill(dis, dis + N, INF);
    dis[s] = 0;
    priority_queue<P, vector<P>, greater<P> > pque;
    pque.push({dis[s], s});

    while(!pque.empty()) {
        P p = pque.top(); pque.pop();
        int i = p.second;
        ll dist = p.first;
        if(dist > dis[i]) continue;

        for(edge e : G[i]) {
            if(e.cost + dis[i] < dis[e.to]) {
                dis[e.to] = e.cost + dis[i];
                pque.push({dis[e.to], e.to});
            }
        }
    }
}

int n, m;
int loc[8];
ll len[8][8];
ll ori[8];
ll dp[8][(1 << 8) + 5];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    for(int i = 0; i < 7; i++) {
        cin >> loc[i];
        loc[i]--;
    }
    dijkstra(0);
    for(int i = 0; i < 7; i++) ori[i] = dis[loc[i]];
    for(int i = 0; i < 7; i++) {
        dijkstra(loc[i]);
        for(int j = 0; j < 7; j++) {
            len[i][j] = dis[loc[j]];
        }
    }
//    memset(dp, 0x3f, sizeof(dp));
//    cout << dp[0][0] + INF << endl;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < ((1 << 8) + 5); j++) dp[i][j] = INF;
    }
    for(int i = 0; i < 7; i++) {
        dp[i][(1 << i)] = ori[i];
    }
    for(int mask = 1; mask < (1 << 7); mask++) {
        for(int i = 0; i < 7; i++) {
            if(!((mask >> i) & 1)) continue;
            for(int j = 0; j < 7; j++) {
                if((mask >> j) & 1) continue;
                dp[j][mask | (1 << j)] = min(dp[j][mask | (1 << j)], dp[i][mask] + len[i][j]);
            }
        }
    }
    ll res = INF;
    for(int i = 0; i < 7; i++) {
        res = min(res, dp[i][(1 << 7) - 1]);
    }
    if(res == INF) cout << -1 << endl;
    else cout << res << endl;



}