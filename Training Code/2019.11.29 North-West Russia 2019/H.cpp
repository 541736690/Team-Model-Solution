#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int maxv = 1e6;

int n, q;
int a[maxn];

int mx;
int sum[maxn], ans[maxv + 5];
set<pair<int,int>> s;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        mx = max(mx, a[i]);
        sum[i] = sum[i-1] + a[i];
        s.insert({sum[i], i});
    }
    scanf("%d",&q);
    while(q--) {
        int k; scanf("%d",&k);
        if(k < mx) {
            printf("Impossible\n");
            continue;
        }
        if(!ans[k]) {
            int x = 0;
            while(x != n) {
                //printf("x = %d\n",x);
                auto it = s.upper_bound({sum[x] + k, n+1});
                it--;
                x = it->second;
                ans[k]++;
            }
        }
        printf("%d\n",ans[k]);
    }
}