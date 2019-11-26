#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e5 + 5;
const ll inf = 1e18;

int n, k;
ll lc, pc, lm, pm;
ll cost, d;
ll a[maxn];

ll give_car[maxn], give_motor[maxn], give_pass[maxn];
ll need_car[maxn], need_motor[maxn];

int main() {
    scanf("%d%d",&n,&k);
    scanf("%lld%lld%lld%lld",&lc,&pc,&lm,&pm);
    scanf("%lld%lld",&cost,&d);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

    sort(&a[1],&a[n+1],[](int x, int y){return x>y;});

    // car
    for(int x=1;x<=n;x++) {
        // for people that a[x] >= lc give away
        if(a[x] >= lc) give_car[x] = min(d, a[x] - lc);
            // for people that a[x] < lc need
        else need_car[x] = lc - a[x];

        give_car[x] += give_car[x-1];
        need_car[x] += need_car[x-1];
    }
    // motor
    for(int x=1;x<=n;x++) {
        // for people that a[x] >= lm give away
        if(a[x] >= lm) give_motor[x] = min(d, a[x] - lm);
            // for people that a[x] < lm need
        else need_motor[x] = lm - a[x];

        give_motor[x] += give_motor[x-1];
        need_motor[x] += need_motor[x-1];
    }
    // passenger
    for(int x=1;x<=n;x++) {
        // for people that a[x] >= 1 give away
        if(a[x] >= 1) give_pass[x] = min(d, a[x] - 1);

        give_pass[x] += give_pass[x-1];
    }

    /*for(int x=1;x<=n;x++) {
        printf("give %d = %d %d %d\n",x,give_car[x]-give_car[x-1],give_motor[x]-give_motor[x-1],give_pass[x]-give_pass[x-1]);
        printf("need %d = %d %d\n",x,need_car[x]-need_car[x-1],need_motor[x]-need_motor[x-1]);
    }*/

    ll ans = inf;

    for(int x=0;x<=n;x++) {
        // last people using car can't use it
        if(x && a[x] + d < lc) continue;

        // pos of last people using motorcycle
        int y = (int)max(0LL, n - (ll)x*k) + x;
        if(y && a[y] + d < lm) continue;

        //printf("x = %d y = %d\n",x,y);

        ll give = give_car[x] + (give_motor[y] - give_motor[x]) + (give_pass[n] - give_pass[y]);
        ll need = need_car[x] + (need_motor[y] - need_motor[x]);
        //printf("\tgive = %d need = %d\n",give,need);
        if(give >= need) {
            ans = min(ans, (ll)need * cost + (ll)x * pc + (ll)(y-x) * pm);
        }
    }

    if(ans == inf) printf("-1");
    else printf("%lld",ans);
}