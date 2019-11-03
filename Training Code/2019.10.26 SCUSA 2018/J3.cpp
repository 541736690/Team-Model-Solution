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
    int dist[MAX_V];
    int prevv[MAX_V], preve[MAX_V];

    void add_edge(int from, int to, int cap, int cost) {
        G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].push_back((edge){from, cap, cost, (int)G[from].size() - 1});
    }

    int get_cost(edge &e) {
        if(e.cap == 1) return e.cost;
        if(e.cap == 2) return -e.cost;
        if(e.cap == 0) return 0;
    }

    int get_cap(edge &e) {
        return min(e.cap, 1);
    }



    int rem;

    int min_cost_flow(int s, int t, int f) {
        int res = 0;
        while(f > 0) {
            queue<P> que;
            fill(dist, dist + V, INF);
            dist[s] = 0;
            que.push(P(0, s));
            while(!que.empty()) {
                P p = que.front(); que.pop();
                int v = p.second;
                if(dist[v] < p.first) continue;
                for(int i = 0; i < G[v].size(); i++) {
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + get_cost(e)) {
                        dist[e.to] = dist[v] + get_cost(e);
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

            int d = f;
            for(int v = t; v != s; v = prevv[v]) {
                d = min(d, get_cap(G[prevv[v]][preve[v]]));
            }
            f -= d;
            res += d * dist[t];
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

        mc.add_edge(a, b, 1, 1);
    }
    int flow = mc.min_cost_flow(s, t, p);
    if(flow == -1) {
        cout << mc.rem << " people left behind" << endl;
        return 0;
    }
    cout << flow << endl;
}