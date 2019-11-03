#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf = 1e11;
const int maxn = 20000 + 5;

ll n, k;
ll a[maxn];

bool check(ll ANS) {
    //printf("Check %lld\n",ANS);
    ll l = 1, r = n;
    for(int i=1;i<=k && l<=r;i++) {
        ll cnt = ((ANS / a[l]) + 1)/2;
        if(cnt == 0) return 0;
        r -= cnt*4;
        l = l+1;
        //printf("\tl = %lld r = %lld (cnt = %lld)\n",l,r,cnt);
    }
    if(l>r) return 1;
    return 0;
}

int main() {
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(&a[1],&a[n+1]);

    ll l = 1, r = inf, ans = -1;
    while(l<=r) {
        ll mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    printf("%lld",ans);
}