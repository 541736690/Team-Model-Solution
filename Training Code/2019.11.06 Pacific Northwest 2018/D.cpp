#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 9;

int k,b;
int wow[130], dp[150][1005][150];

int f(int i, int rem, int has) {
    if(i==-1) {
        if(rem == 0) return has;
        return 0;
    }
    return dp[i][rem][has];
}

int main() {
    scanf("%d%d",&k,&b);
    wow[0] = 1%k;
    for(int i=1;i<b;i++) wow[i] = (wow[i-1]*2)%k;//, printf("wow %d = %d\n",i,wow[i]);

    for(int i=0;i<b;i++) {
        for(int rem=0;rem<k;rem++) {
            for(int has=0;has<b;has++) {
                dp[i][rem][has] = (f(i-1,(rem+wow[i])%k,has+1) + f(i-1,rem,has))%mod;
            }
        }
    }
    printf("%d",dp[b-1][0][0]);
}