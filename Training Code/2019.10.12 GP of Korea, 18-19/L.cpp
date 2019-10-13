#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int n, m;
int a[maxn];
int sum[maxn], nxt[maxn];
pair<int,int> res[maxn];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++) {
        sum[i] = sum[i-1] + (a[i] >= a[i-1]);
    }
    for(int x=1;x<=n;x++) {
        int l = x, r = n;
        nxt[x] = x+1;
        while(l<=r) {
            int mid = (l+r)/2;
            int val = sum[mid]-sum[x];
            if(val == 0 || val == mid-x) {
                nxt[x] = mid+1;
                l = mid+1;
            }
            else r = mid-1;
        }
    }
    for(int id=2;id<=n;id++) {
        int mn = id;
        int x = 1;
        int cnt = 0, bad = 0;
        while(x<=n) {
            cnt++;
            if(nxt[x] == n+1) break;
            mn = min(mn, n-x+1);
            if(nxt[x]-x >= mn) {
                x = nxt[x];
            }
            else {
                bad += mn - (nxt[x]-x);
                x = x + mn;
            }
        }
        res[id] = {cnt, bad};
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++) {
        int mn; scanf("%d",&mn);
        printf("%d %d\n",res[mn].first,res[mn].second);
    }
}