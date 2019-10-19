#include <bits/stdc++.h>
using namespace std;

const int N = 26;
const double INF = 1e18;
int d, n;

struct Pt {
    int x, y;
};

double get_dist(Pt p1, Pt p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
vector<Pt> good[N], bad[N];

double dis[(1 << 17)][17];
double len[17][17];
double get_cost(vector<Pt> &pts) {
    int n = pts.size();
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) len[i][j] = get_dist(pts[i], pts[j]);
    for(int mask = 0; mask < (1 << n); mask++) fill(dis[mask], dis[mask] + n, INF);
    dis[(1 << 0)][0] = 0;
    for(int mask = 1; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if(!((mask >> i) & 1)) continue;
            for(int j = 0; j < n; j++) {
                if(i == j || !((mask >> j) & 1)) continue;
                dis[mask][i] = min(dis[mask][i], dis[mask ^ (1 << i)][j] + len[i][j]);
            }
        }
    }
    double res = INF;
    for(int i = 0; i < n; i++) {
        res = min(res, dis[(1 << n) - 1][i] + len[i][0]);
    }
    return res;
}

struct edge {
    int to, cap;
    double cost;
    int rev;
};

double cost[N][N];

struct MinCost {
    static const int MAX_V = 105;
//    const int INF = (int)1e9;
    typedef pair<double, int> P;

    int V;
    vector<edge> G[MAX_V];
    double h[MAX_V];
    double dist[MAX_V];
    int prevv[MAX_V], preve[MAX_V];

    void add_edge(int from, int to, int cap, double cost) {
        G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
    }

    double min_cost_flow(int s, int t, int f) {
        double res = 0;
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
            if(dist[t] == INF) return -1;
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

}mc;

int main() {
    cin >> d;
    n = d / 2;
    for(int i = 0; i < n; i++) {
        int tn;
        cin >> tn;
        for(int j = 0; j < tn; j++) {
            int x, y; cin >> x >> y;
            good[i].push_back({x, y});
        }
    }
    for(int i = 0; i < n; i++) {
        int tn;
        cin >> tn;
        for(int j = 0; j < tn; j++) {
            int x, y; cin >> x >> y;
            bad[i].push_back({x, y});
        }
    }
    double res1 = 0;
    for(int i = 0; i < n; i++) res1 += get_cost(good[i]);
    for(int i = 0; i < n; i++) res1 += get_cost(bad[i]);

    int s = 2 * n, t = 2 * n + 1;
    mc.V = 2 * n + 2;
    double mx_cost = 0;
    for(int i = 0; i < n; i++) {
        mc.add_edge(s, i, 1, 0);
        mc.add_edge(i + n, t, 1, 0);
        for(int j = 0; j < n; j++) {
            vector<Pt> cur;
            for(auto &p : good[i]) cur.push_back(p);
            for(auto &p : bad[j]) cur.push_back(p);
            cost[i][j] = get_cost(cur);
            mc.add_edge(i, j + n, 1, cost[i][j]);
        }
    }
    cout << fixed << setprecision(10) << res1 << " " << mc.min_cost_flow(s, t, n) << '\n';


}