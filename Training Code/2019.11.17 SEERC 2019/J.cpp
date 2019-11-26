#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;

int n;
vector<int> way[maxn];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n*(n-1)/2;i++) {
        int u,v,val; scanf("%d%d%d",&u,&v,&val);
        way[u].push_back(val);
        way[v].push_back(val);
    }
    long long ans = 0;
    for(int u=1;u<=n;u++) {
        sort(way[u].begin(),way[u].end());
        for(int i=1;i<n-1;i+=2) ans += way[u][i];
    }
    printf("%lld",ans);
}