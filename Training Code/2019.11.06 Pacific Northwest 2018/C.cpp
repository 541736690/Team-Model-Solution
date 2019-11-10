//
// Created by 54173 on 11/6/2019.
//
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int mod = 998244353;

int n,k;
int a[maxn];
int wow[maxn];
int dp[maxn][maxn];

int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(&a[1],&a[n+1]);
    for(int i=n;i>=1;i--) {
        if(a[i] == a[i+1]) wow[i] = wow[i+1];
        else wow[i] = i+1;
    }
    dp[n+1][0] = 1;
    for(int x=n;x>=1;x--) {
        for(int k=n;k>=0;k--) {
            if(k == 0) dp[x][k] = 1;
            else {
                dp[x][k] = (dp[x+1][k] + dp[wow[x]][k-1])%mod;
            }
        }
    }
    printf("%d",dp[1][k]);
}