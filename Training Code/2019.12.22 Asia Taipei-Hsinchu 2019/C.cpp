#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;

int n;
int a[maxn];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    for(int x=1;x<=n;x++) {
        for(int y=1;y<=n;y++) {
            if(x==y) continue;
            for(int z=1;z<=n;z++) {
                if(x==z || y==z) continue;
                int t = (a[x]-a[y])/a[z];
                if(t*a[z] != a[x]-a[y]) return !printf("no");
            }
        }
    }
    printf("yes");
}