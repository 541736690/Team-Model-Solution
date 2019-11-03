//
// Created by 54173 on 11/2/2019.
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#define ii pair<int,int>
#define X first
#define Y second

using namespace std;
const int maxn = 100001;
int n,m;
int u[maxn+1],v[maxn+1];
vector<int> V[maxn+1];
vector<int> R[maxn+1];
vector<int> G[maxn+2];

int dpUp[maxn+1],dpDown[maxn+1]; // number of edges

int low[maxn+1],pre[maxn+1];
set<int> nG[maxn+1];
int cmp[maxn+1];
int ccnt = 0;
stack<int> S;
int cnt = 0;

void dfs(int v,int id) {
    pre[v] = low[v] = ++cnt;
    S.push(v);
    for (int j=0; j<G[v].size(); j++)
    {
        edge e = G[v][j];
        if (e.id == id)
            continue;
        if (pre[e.to] == )

}
int calDpUp(int x) {
    if (dpUp[x]!=-1)
        return dpUp[x];

    dpUp[x] = 0;
    for (int y: R[x])
        dpUp[x] = max(dpUp[x],calDpUp(y)+1);

    return dpUp[x];
}

int calDpDown(int x) {
    if (dpDown[x] != -1)
        return dpDown[x];

    dpDown[x] = 0;
    for (int y: V[x])
        dpDown[x] = max(dpDown[x], calDpDown(y) + 1);

    return dpDown[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];
        V[u[i]].push_back(v[i]);
        R[v[i]].push_back(u[i]);
    }

    for (int i=1; i<=n; i++) {
        V[0].push_back(i);
        R[i].push_back(n + 1);
    }

    memset(dpUp, -1, sizeof(dpUp));
    memset(dpDown, -1, sizeof(dpDown));

    for (int i=1; i<=n; i++) {
        calDpUp(i);
        calDpDown(i);
    }


    int maxLength = calDpDown(0);
    for (int i=1; i<=m; i++) {
        if (calDpUp(u[i]) + calDpDown(v[i]) + 1 == maxLength)
            G[u[i]].push_back(v[i]);

    }


    return 0;
}








    return 0;
}