#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 5000 + 5;
const ll mod = 1e9 + 7;

int n, m;
int same[maxn], diff[maxn];
ll dp[maxn][maxn];

ll add(ll x, ll y) {
    return ((x+y)%mod + mod)%mod;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        same[i] = i;
        diff[i] = 0;
    }
    for(int i=1;i<=m;i++) {
        int l, r; char type[10];
        scanf("%d%d %s",&l,&r,type);
        if(type[0]=='s') same[r] = min(same[r], l);
        else diff[r] = max(diff[r], l);
        //printf("r = %d: %d %d\n",r,same[r],diff[r]);
    }

    for(int x=n;x>=0;x--) {
        for(int y=n;y>=0;y--) {
            int i = max(x,y);
            if(same[i] != i && same[i] <= min(x,y)) dp[x][y] = 0;
            else if(diff[i] != 0 && min(x,y) < diff[i]) dp[x][y] = 0;
            else if(i==n) dp[x][y] = 1;
            else dp[x][y] = add(dp[i+1][y], dp[x][i+1]);
        }
    }

    printf("%lld",dp[0][0]);
}