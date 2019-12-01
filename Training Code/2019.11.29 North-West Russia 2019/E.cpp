//
// Created by 54173 on 11/29/2019.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 200000;
int n,m;
vector<int> V[maxn+1];
vector<int> G[maxn+1];
bool selected[maxn+1];
int root;
int parent[maxn+1];
int hasSelected[maxn+1];

void dfs(int x)
{
    hasSelected[x]|=selected[x];
    for (int y: V[x])
    {
        if (parent[y]==0)
        {
            parent[y] = x;
            dfs(y);
            hasSelected[x]|=hasSelected[y];
        }
    }
}

void buildGraph(int x)
{
    for (int y: V[x])
    {
        if (parent[y]==x)
        {
            if (hasSelected[y]) {
                G[x].push_back(y);
                G[y].push_back(x);
                buildGraph(y);
            }
        }
    }
}

queue<int> Q;
int dist[maxn+1];
int dist2[maxn+1];

int farthestFrom(int x,int* dist)
{
    while (!Q.empty())
        Q.pop();
    for (int i=1; i<=n; i++)
        dist[i] = maxn+1;

    int res = x;
    Q.push(x);
    dist[x] = 0;
    do
    {
        int p = Q.front();
        res = p;
        Q.pop();
        for (int u: G[p])
        {
            if (dist[u]>dist[p]+1)
            {
                dist[u] = dist[p]+1;
                Q.push(u);
            }
        }
    }
    while (!Q.empty());

    return res;
}


int findCenter(int x)
{
    x = farthestFrom(x,dist);
    int y = farthestFrom(x,dist);

    /*cout << y << '\n';
    for (int i=1; i<=n; i++)
        cout << dist[i] << ' ';
    cout << '\n';*/
    int length = dist[y];
    //cout << length << '\n';
    farthestFrom(y,dist2);
    int current = x;

    for (int i=1; i<=length/2; i++)
    {
        for (auto y: G[current])
        {
            if (dist[current]+dist2[y]+1==length)
            {
                current = y;
                break;
            }
        }
    }

    return current;
}

bool checkCenter(int x)
{
    while (!Q.empty())
        Q.pop();

    for (int i=1; i<=n; i++)
        dist[i] = maxn+1;

    Q.push(x);
    dist[x] = 0;
    do
    {
        int p = Q.front();
        Q.pop();
        for (int u: G[p])
        {
            if (dist[u]>dist[p]+1)
            {
                dist[u] = dist[p]+1;
                Q.push(u);
            }
        }
    }
    while (!Q.empty());

    int res = -1;
    for (int i=1; i<=n; i++)
    {
        if (selected[i])
        {
            if (res==-1)
                res = dist[i];
            else
                if (dist[i]!=res)
                    return false;
        }
    }

    return true;


}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i=1; i<=n-1; i++)
    {
        int u,v;
        cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    for (int i=1; i<=m; i++)
    {
        int x;
        cin >> x;
        selected[x] = true;
        root = x;
    }

    memset(parent,0,sizeof(parent));
    memset(hasSelected,false,sizeof(hasSelected));
    parent[root] = -1;
    dfs(root);
    buildGraph(root);

    int center = findCenter(root);
    if (checkCenter(center))
    {
        cout << "YES\n" << center;
    }
    else
        cout << "NO";

    return 0;



}

