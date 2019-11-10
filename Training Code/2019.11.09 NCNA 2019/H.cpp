#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
const int inf = 1e9;

int n, m;
vector<int> way[maxn];
int dis[maxn];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        int u,v; scanf("%d%d",&u,&v);
        way[u].push_back(v);
        way[v].push_back(u);
    }
    for(int i=1;i<=n;i++) dis[i] = inf;
    queue<int> q;
    dis[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        //printf("u = %d: dis[u] = %d\n",u,dis[u]);
        for(auto v : way[u]) {
            if(dis[v] > dis[u]+1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    printf("%d",dis[n]-1);
}