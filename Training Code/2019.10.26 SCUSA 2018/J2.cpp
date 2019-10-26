#include <bits/stdc++.h>
using namespace std;

const int N = 1005, MAX_V = 3005, INF = (int)1e9;

typedef pair<int, int> P;
struct edge {
    int to, cap, cost, rev;
};

struct MinCostFlow {
    int V;
    vector<edge> G[MAX_V];
    int h[MAX_V];
    int dist[MAX_V];
    int prevv[MAX_V], preve[MAX_V];

    void add_edge(int from, int to, int cap, int cost) {
        G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
    }

    int rem;

    int min_cost_flow(int s, int t, int f) {
        int res = 0;
        fill(h, h + V, 0);
        while(f > 0) {
            priority_queue<P, vector<P>, greater<P> > que;
            fill(dist, dist + V, INF);
            dist[s] = 0;
            que.push(P(0, s));
            while(!que.empty()) {
                P p = que.top(); que.pop();
                int v = p.second;
                if(dist[v] < p.first) continue;
                for(int i = 0; i < G[v].size(); i++) {
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(P(dist[e.to], e.to));
                    }
                }
            }
            if(dist[t] == INF) {
                rem = f;
                return -1;
            }
            for(int v = 0; v < V; v++) h[v] += dist[v];

            int d = f;
            for(int v = t; v != s; v = prevv[v]) {
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for(int v = t; v != s; v = prevv[v]) {
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;

    }

} mc;

int p, n, m;

int main() {
    cin >> p >> n >> m;
    int s = n + 2 * m, t = s + 1;

    mc.V = t + 1;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if(a == -2) a = s;
        else if(a == -1) a = t;

        if(b == -2) b = s;
        else if(b == -1) b = t;

        int e1 = 2 * i + n, e2 = e1 + 1;
        mc.add_edge(a, e1, 1, 0);
        mc.add_edge(b, e1, 1, 0);
        mc.add_edge(e2, a, 1, 0);
        mc.add_edge(e2, b, 1, 0);
        mc.add_edge(e1, e2, 1, 1);
    }
    int flow = mc.min_cost_flow(s, t, p);
    if(flow == -1) {
        cout << mc.rem << " people left behind" << endl;
        return 0;
    }
    cout << flow << endl;
}