#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 33, INF = (int)1e9;

struct edge {
    int to, cap, rev;
    edge(int _to, int _cap, int _rev) {
        to = _to, cap = _cap, rev = _rev;
    }
};

struct Dinic {
    static const int N = 2000;
    vector<edge> G[N];
    int level[N], iter[N];

    void add_edge(int from, int to, int cap) {
        G[from].push_back(edge(to, cap, (int)G[to].size()));
        G[to].push_back(edge(from, 0, G[from].size() - 1));
    }

    void bfs(int s) {
        memset(level, -1, sizeof(level));
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()) {
            int v = que.front(); que.pop();
            for(int i = 0; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                if(e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    ll dfs(int v, int t, int f) {
        if(v == t) return f;

        for(int &i = iter[v]; i < (int)G[v].size(); i++) {
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]) {
                ll d = dfs(e.to, t, min(e.cap, f));
                if(d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    ll max_flow(int s, int t) {
        ll flow = 0;
        for(;;) {
            bfs(s);
            if(level[t] < 0) return flow;
            memset(iter, 0, sizeof(iter));
            ll f;
            while((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
    }
} dc;

int n, m, c;
string str[N];
int cst[N];

bool in_bound(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

int f(int i, int j) {
    return i * m + j;
}

int main() {
    cin >> n >> m >> c;
    swap(n, m);
    for(int i = 0; i < n; i++) cin >> str[i];
    for(int i = 0; i < c; i++) cin >> cst[i];
    int s = n * m * 2, t = s + 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(str[i][j] == 'B') dc.add_edge(s, f(i, j), INF);

            int cost = (str[i][j] == '.' || str[i][j] == 'B') ? INF : cst[str[i][j] - 'a'];
            dc.add_edge(f(i, j), f(i, j) + m * n, cost);

            bool bound = false;
            for(int d = 0; d < 4; d++) {
                if(in_bound(i + dx[d], j + dy[d])) {
                    dc.add_edge(f(i, j) + m * n, f(i + dx[d], j + dy[d]), INF);
                }
                else bound = true;
            }
            if(bound) {
                dc.add_edge(f(i, j) + m * n, t, INF);
            }
        }
    }
    ll flow = dc.max_flow(s, t);
    if(flow >= INF) {
        cout << "-1" << endl;
        return 0;
    }
    cout << flow << endl;

}