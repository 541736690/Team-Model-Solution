#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 2e5 + 5;

int n;
ll a[maxn], sum[maxn];
vector<int> pos;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]), sum[i] = sum[i-1] + a[i];

    ll ans = 0;

    pos.push_back(n+1);
    for(int x=n;x>=1;x--) {
        if(a[x] != 1) pos.push_back(x);
        ll SUM = 0, MUL = 1;
        //printf("x = %d\n",x);
        for(int i=(int)pos.size()-1;i>0;i--) {
            int y = pos[i];
            //printf("\ty = %d\n",y);
            SUM = sum[y] - sum[x-1];
            if((long double)MUL * a[y] > (long double)3e14) break;
            MUL = MUL * a[y];
            ll K = pos[i-1] - pos[i] - 1;
            ll T = MUL - SUM;
            if(T <= K) {
                if(x==y && T>=1) ans++;
                else if(y>x && T>=0) ans++;
            }
        }
    }

    printf("%lld",ans);
}