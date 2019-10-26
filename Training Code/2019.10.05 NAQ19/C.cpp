#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;

int n,m;
int a[maxn], b[maxn];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        int x, ta, tb; scanf("%d%d%d",&x,&ta,&tb);
        a[x] += ta;
        b[x] += tb;
    }
    long long wa = 0, wb = 0, sum = 0;
    for(int i=1;i<=m;i++) {
        if(a[i] > b[i]) {
            wa += a[i] - ((a[i]+b[i])/2 + 1);
            wb += b[i];
            printf("A %d %d\n", a[i] - ((a[i]+b[i])/2 + 1), b[i]);
        }
        else {
            wb += b[i] - ((a[i]+b[i])/2 + 1);
            wa += a[i];
            printf("B %d %d\n", a[i], b[i] - ((a[i]+b[i])/2 + 1));
        }
        sum += a[i] + b[i];
    }
    printf("%.10lf",(double)abs(wa-wb)/sum);
}