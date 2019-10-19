//
// Created by 54173 on 10/19/2019.
//
#include <bits/stdc++.h>

using namespace std;
const int N = 2505;
typedef long long ll;

ll res = 0;
int n,m;
int a[N][N];

struct SCC {
    vector<int> G[N], rG[N], vs;
    vector<int> nG[N];
    bool used[N];
    int cmp[N];
    int sz[N];
    int in_deg[N];


    void add_edge(int u, int v) {
        G[u].push_back(v);
        rG[v].push_back(u);
    }

    void dfs(int v) {
        used[v] = true;
        for(int nxt : G[v]) {
            if(!used[nxt]) dfs(nxt);
        }
        vs.push_back(v);
    }

    void rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for(int nxt : rG[v]) {
            if(!used[nxt]) rdfs(nxt, k);
        }
    }

    int scc()
    {
        memset(used,0,sizeof(used));
        vs.clear();
        for (int v=0; v<n; v++)
        {
            if (!used[v])
                dfs(v);
        }

        memset(used,0,sizeof(used));
        int k=0;
        reverse(vs.begin(),vs.end());
        for (int v: vs)
        {
            if (!used[v])
                rdfs(v,k++);
        }
        return k;
    }

    void build() {
        int k = scc();
        for(int i = 0; i < n; i++) {
            sz[cmp[i]]++;
        }

        for(int i = 0; i < n; i++) {
            for(int nxt : G[i]) {
                if(cmp[i] == cmp[nxt]) continue;
                nG[cmp[i]].push_back(cmp[nxt]);
                in_deg[cmp[nxt]]++;
            }
        }
        ll sum = 0;
        queue<int> que;
        for(int i = 0; i < k; i++) {
            if(in_deg[i] == 0) que.push(i);
        }
        while(!que.empty()) {
            int v = que.front(); que.pop();
            res += (sum + sz[v] - 1) * sz[v];
            for(int nxt : nG[v]) {
                in_deg[nxt]--;
                if(in_deg[nxt] == 0) {
                    que.push(nxt);
                }
            }
            sum += sz[v];
        }
        cout << res - m << endl;
    }

} scc;

int main()
{
//    ios_base::sync_with_stdio(0);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            m += a[i][j];
            if(a[i][j]) scc.add_edge(i, j);
        }
    }
    scc.build();


    return 0;
}
