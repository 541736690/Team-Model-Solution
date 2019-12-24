#include<bits/stdc++.h>
using namespace std;

int K, L;
int a[2500];

void solve(int tnum) {
    scanf("%d%d",&K,&L); K++;
    if(L >= 2000) {
        printf("-1\n");
        return ;
    }
    // long long sum = -1;
    a[1] = -1;
    for(int i=2;i<2000;i++) {
        a[i] = min(999999, K) + 1;
        // sum += a[i];
        K -= min(999999, K);
    }
    // printf("%lld and %lld\n",sum*1999,(sum+1)*1998);
    printf("1999\n");
    for(int i=1;i<2000;i++) printf("%d ",a[i]);
    printf("\n");
}

int main() {
    int tnum; scanf("%d",&tnum);
    for(int i=1;i<=tnum;i++) solve(i);
}