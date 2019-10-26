#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

int n;
int good[maxn][maxn];
int dp[maxn][maxn];
int p[maxn];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int val; scanf("%d",&val);
            good[i][j] = val;
            good[i][j+n] = val;
            good[j][i] = val;
            good[j][i+n] = val;
        }
    }
    for(int i=1;i<=n;i++) p[i] = p[i+n] = i;
    for(int sz=2;sz<=n;sz++) {
        for(int x=1;x<=n;x++) {
            int y = x+sz-1;
            dp[x][y] = max(dp[x+1][y], dp[x][y-1]);
            for(int i=x;i<y;i++) dp[x][y] = max(dp[x][y], dp[x][i] + dp[i+1][y]);
            if(good[x][y]) dp[x][y] = max(dp[x][y], dp[x+1][y-1] + 1);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans = max(ans, dp[i][i+n-1]);
    printf("%d",ans);
}