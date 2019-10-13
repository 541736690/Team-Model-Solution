//
// Created by 54173 on 10/12/2019.
//
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 200000;
int n,C,q;
vector<int> V[maxn+1];
int color[maxn+1];
int parent[maxn+1];
int cnt[maxn+1];

void dfs(int x)
{
    for (int y: V[x])
        if (parent[y]==0)
        {
            parent[y]=x;
            dfs(y);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.ans","w",stdout);
    cin >> n >> C >> q;
    for (int i=1; i<n; i++)
    {
        int u,v;
        cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    parent[1] = -1;
    dfs(1);

    for (int i=1; i<=q; i++)
    {
        int u,c,m;
        cin >> u >> c >> m;
        int p=u;
        do
        {
            color[p] = c;
            p = parent[p];
        }
        while (p!=-1);
        for (int i=1; i<=C; i++)
            cnt[i]=0;
        for (int i=2; i<=n; i++)
            cnt[color[i]]++;
        int res = 0;
        for (int i=1; i<=C; i++)
            if (cnt[i]==m)
                res++;

            cout << res << '\n';

    }


    return 0;
}
