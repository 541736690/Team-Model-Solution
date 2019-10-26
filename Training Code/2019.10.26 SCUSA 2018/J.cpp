#include <bits/stdc++.h>
using namespace std;

const int N = 1050;

struct edge {
    int to, cap, rev;
    edge(int _to, int _cap, int _rev) {
        to = _to, cap = _cap, rev = _rev;
    }
};

int cnt[N][N];

struct Dinic {
    static const int INF = (int)1e9;
    vector<edge> G[N];

    int level[N], iter[N];

    void add_edge(int from, int to, int cap) {
        G[from].push_back(edge(to, cap, G[to].size()));
        G[to].push_back(edge(from, cap, G[from].size() - 1));
    }

    void bfs(int s) {
        memset(level, -1, sizeof(level));
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()) {
            int v=  que.front(); que.pop();
            for(int i = 0; i < G[v].size(); i++) {
                edge &e = G[v][i];
                if(e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if(v == t) return f;

        for(int &i = iter[v]; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(e.cap, f));
                if(d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    cnt[v][e.to]++;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        for(;;) {
            bfs(s);
            if(level[t] < 0) return flow;
            memset(iter, 0, sizeof(iter));
            int f;
            while((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
    }
} dinic;

int p, n, m;

int main() {
    cin >> p >> n >> m;
    int s = n, md = s + 1, t = md + 1;
    dinic.add_edge(s, md, p);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if(a == -2) a = md;
        else if(a == -1) a = t;

        if(b == -2) b = md;
        else if(b == -1) b = t;
        dinic.add_edge(a, b, 1);
    }
    int flow = dinic.max_flow(s, t);
    if(flow != p) {
        cout << p - flow << " people left behind" << endl;
        return 0;
    }
    int sum = 0;
    for(int i = 0; i <= t; i++) {
        for(int j = i + 1; j <= t; j++) {
            if(cnt[i][j] != cnt[j][i]) sum++;
        }
    }
    cout << sum - 1 << endl;

}