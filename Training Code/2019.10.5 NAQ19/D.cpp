#include<bits/stdc++.h>
using namespace std;

int n, mx;
int good[205];

int main() {
    scanf("%d",&n);
    mx = 1;
    for(int i=1;i<=n;i++) {
        int x; scanf("%d",&x);
        mx = max(mx, x);
        good[x] = 1;
    }
    int bad = 0;
    for(int i=1;i<=mx;i++) if(!good[i]) bad = 1, printf("%d\n",i);
    if(!bad) printf("good job");
}