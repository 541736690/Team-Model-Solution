#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e8 + 50;

long long a[10005];
bitset<maxn+50> bit;

int main() {
    long long want;
    long long wow = 1;
    scanf("%lld%lld",&a[0],&want);
    bit[a[0]] = 1;
    for(int i=1;i<=10000;i++) {
        if(bit[want]) {
            printf("%d\n",i);
            return 0;
        }
        while(bit[wow]) wow++;
        a[i] = a[i-1] + wow;
        //printf("%lld ",a[i]);
        if(a[i]<=maxn) bit[a[i]] = 1;
        for(int j=0;j<i;j++) if(a[i]-a[j]<=maxn) bit[a[i]-a[j]] = 1;
    }
}