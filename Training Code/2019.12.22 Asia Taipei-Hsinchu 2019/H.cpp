#include<bits/stdc++.h>
using namespace std;

int main() {
    int tnum; scanf("%d",&tnum);
    while(tnum--) {
        long long n; scanf("%lld",&n);
        printf("%lld\n",(n*(n+1))^(n+1));
    }
}