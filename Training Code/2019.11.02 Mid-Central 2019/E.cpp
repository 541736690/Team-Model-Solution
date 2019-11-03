#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
const int mod = (int)1e9 + 7;

struct edge {
    int to, c;
};

int n;
vector<edge> G[N];
int l[N], r[N], p[N];
int vis[N];

bool dfs(int v, int col) {
    vis[v] = col;
    for(edge &e : G[v]) {
        if(vis[e.to] == -1) {
            if(!dfs(e.to, col ^ e.c)) return false;
        }
        else if((vis[e.to] ^ e.c) != vis[v]) return false;
    }
    return true;
}

void add_edge(int u, int v, int c) {
    G[u].push_back({v, c});
    G[v].push_back({u, c});
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> p[i];

    }

    ll fres = 0;

    for(int odd = 0; odd < 2; odd++) {
//        cout << "odd : " << odd << endl;
        for(int i = 0; i <= n; i++) G[i].clear();

        for(int i = 1; i <= n; i++) {
            int lb = i - l[i], rb = i + r[i];
            if(1 <= lb && rb <= n) add_edge(lb - 1, rb, p[i]);
            else if(lb < 1) {
                add_edge(rb, lb + n - 1, odd ^ p[i]);
            }
            else {
                add_edge(rb - n, lb - 1, odd ^ p[i]);
            }
        }
        add_edge(0, n, odd);
        memset(vis, -1, sizeof(vis));
        int cnt = 0;
        for(int i = 0; i <= n; i++) {
            if(vis[i] == -1) {

                if(!dfs(i, 0)) {
                    cnt = -1;
                    break;
                }
                cnt++;
            }
        }
//        cout << cnt << endl;
        if(cnt != -1) {
            int res = 1;
            cnt--;
            while(cnt--) res = res * 2 % mod;
            fres += res;
        }
    }
    cout << (fres % mod + mod) % mod << endl;
}