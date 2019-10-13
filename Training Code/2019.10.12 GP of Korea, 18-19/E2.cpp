#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int n, m;
set<int> G[N];
int vis[N];
queue<int> que;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    for(int i = 0; i < n; i++) {
        if(G[i].size() == 2) {
            que.push(i);
            vis[i] = true;
        }
    }
    while(!que.empty()) {
        int mid = que.front(); que.pop();
        if(G[mid].size() != 2) continue;
        int u = *G[mid].begin(), v = *G[mid].rbegin();
        G[mid].erase(u);
        G[mid].erase(v);
        G[u].erase(mid);
        G[v].erase(mid);
        G[u].insert(v);
        G[v].insert(u);
        if(G[u].size() == 2 && !vis[u]) {
            que.push(u);
            vis[u] = true;
        }
        if(G[v].size() == 2 && !vis[v]) {
            que.push(v);
            vis[v] = true;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += G[i].size();
    }
//    cout << cnt << endl;
    if(cnt == 2) cout << "Yes" << '\n';
    else cout << "No" << '\n';

}