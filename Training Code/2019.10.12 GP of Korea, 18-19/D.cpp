#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 50;
typedef pair<int, int> P;

int n, m;
vector<int> G[N];
P p[N], dp[N];
int in_deg[N];
int vis[N];
vector<int> in[N];

void dfs(int v) {
    vis[v] = -1;
    for(int nxt : G[v]) {
        if(vis[nxt] == -1) {
            cout << "-1\n";
            exit(0);
        }
        if(vis[nxt] == 0) dfs(nxt);
    }
    vis[v] = 1;
}

P get(int v) {
    if(dp[v].first != -1) return dp[v];

    vector<int> V;
    for(int nxt : G[v]) {
        V.push_back(get(nxt).second);
    }
    sort(V.begin(), V.end());
    dp[v] = p[v];
    for(int i = 0; i < V.size(); i++) {
        dp[v].second = min(dp[v].second, V[i] - i - 1);
    }
    return dp[v];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
    }
    for(int i = 0; i < n; i++) {
        sort(G[i].begin(), G[i].end());
        G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());
        for(int nxt : G[i]) in_deg[nxt]++;
    }
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) dfs(i);
    }
    fill(dp, dp + n, P{-1, -1});
    for(int i = 0; i < n; i++) {
        get(i);
//        cout << dp[i].first << " " << dp[i].second << endl;
        if(dp[i].second < dp[i].first) {
            cout << "-1" << endl;
            exit(0);
        }
    }
    priority_queue<P, vector<P>, greater<P> > pque;
    for(int i = 0; i < n; i++) {
        if(in_deg[i] == 0) {
            in[dp[i].first].push_back(i);
        }
    }
    vector<int> res;
    for(int i = 1; i <= n; i++) {
        for(int x : in[i]) {
            pque.push({dp[x].second, x});
        }

        if(pque.empty() || pque.top().first < i) {
//            cout << pque.top().first << " and " << i << " " << pque.empty() << endl;
//            cout << "exit in " << i << endl;
            cout << "-1\n";
            exit(0);
        }
        P p = pque.top(); pque.pop();
        int v = p.second;
        res.push_back(v);
        for(int nxt : G[v]) {
            in_deg[nxt]--;
            if(in_deg[nxt] == 0) {
                if(dp[nxt].first <= i) {
                    pque.push({dp[nxt].second, nxt});
//                    cout << "pushing " << dp[nxt].second << ", " << nxt << endl;
                }
                else in[dp[nxt].first].push_back(nxt);
            }
        }
    }

    for(int x : res) cout << x + 1 << '\n';



}