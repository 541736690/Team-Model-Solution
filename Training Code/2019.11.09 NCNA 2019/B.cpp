#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n;
string str[N];
vector<int> G[N];
int cnt[2] = {0, 0};
int vis[N];
const int INF = (int)1e9;

void dfs(int v, int c) {
    vis[v] = c;
    cnt[c]++;
    for(int nxt : G[v]) {
        if(vis[nxt] == -1) {
            dfs(nxt, !c);
        }
    }
}

bool check(string &s1, string &s2) {
    int len = s1.length();
    int p1 = -1, p2 = -1;
    for(int i = 0; i < len; i++) {
        if(s1[i] == s2[i]) continue;
        if(p1 == -1) {
            p1 = i;
        }
        else if(p2 == -1) {
            p2 = i;
        }
        else return false;
    }
    if(p2 == -1) return false;
    return (s1[p1] == s2[p2] && s1[p2] == s2[p1]);
}

struct edge {
    int to, cap, rev;
    edge(int _to, int _cap, int _rev) {
        to = _to, cap = _cap, rev = _rev;
    }
};

struct Ford {
    vector<edge> G[N];
    bool used[N];

    void add_edge(int from, int to, int cap) {
        G[from].push_back(edge(to, cap, (int)G[to].size()));
        G[to].push_back(edge(from, 0,(int)G[from].size() - 1));
    }

    int dfs(int v, int t, int f) {
        if(v == t) return f;
        used[v] = true;

        for(int i = 0; i < (int)G[v].size(); i++) {
            edge &e = G[v][i];
            if(!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(e.cap, f));
                if(d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int f = 0;
        for(;;) {
            fill(used, used + N, false);
            int d = dfs(s, t, INF);
            if(d == 0) return f;
            f += d;
        }
    }
} flow;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(check(str[i], str[j])) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    fill(vis, vis + n, -1);
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(vis[i] == -1) {
            cnt[0] = cnt[1] = 0;
            dfs(i, 0);
            res += max(cnt[0], cnt[1]);
        }
    }
    int s = n, t = n + 1;
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) {
            flow.add_edge(s, i, 1);
            for(int nxt : G[i]) flow.add_edge(i, nxt, 1);
        }
        else {
            flow.add_edge(i, t, 1);
        }
    }
    cout << n - flow.max_flow(s, t) << endl;
}