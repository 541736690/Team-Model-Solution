#include<bits/stdc++.h>
using namespace std;

#define ll long long
const long double PI = acos((long double)-1.0);
const long double eps = 1e-16;
const long long ieps = 1e16;
const int maxn = 1e5 + 5;

int n;
long double t[maxn], s[maxn], a[maxn], delta[maxn];

map<ll, pair<long double, long double>> mp;

ll wow(long double x) {
    ll t1 = (ll)x;
    ll t2 = (ll)((x-t1)*ieps);
    return t1 * ieps + t2;
}

void add(long double l, long double r, long double v1, long double v2) {
    if(r - l < eps) return ;
    //printf("add [%.3lf, %.3lf) : %.3lf %.3lf\n",l,r,v1,v2);
    mp[wow(l)].first += v1;
    mp[wow(l)].second += v2;
    mp[wow(r)].first -= v1;
    mp[wow(r)].second -= v2;
    mp[wow(r)-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> t[i] >> s[i] >> a[i];
        if(s[i] != 0) delta[i] = t[i] / s[i];
    }

    long double extra = 0;

    for(int i=1;i<=n;i++) {
        if(s[i] == 0) {
            extra += t[i];
            continue;
        }

        long double L = a[i] - PI, R = a[i] + PI;

        if(L < 0) {
            add(max(L + 2*PI, a[i] - delta[i]), 2*PI, t[i] - s[i] * (a[i] + 2*PI), s[i]);
            add(max((long double)0, a[i] - delta[i]), a[i], t[i] - s[i] * a[i], s[i]);
        }
        else {
            add(max(L, a[i] - delta[i]), a[i], t[i] - s[i] * a[i], s[i]);
        }

        if(R >= 2*PI) {
            add(0, min(R - 2*PI, a[i] + delta[i] + eps), t[i] + s[i] * (a[i] - 2*PI), -s[i]);
            add(a[i], min(2*PI, a[i] + delta[i] + eps), t[i] + s[i] * a[i], -s[i]);
        }
        else {
            add(a[i], min(R, a[i] + delta[i] + eps), t[i] + s[i] * a[i], -s[i]);
        }

        //printf("------------------------------\n");
    }

    long double ans = 0, v1 = 0, v2 = 0;
    for(auto tmp : mp) {
        v1 += tmp.second.first;
        v2 += tmp.second.second;
        ans = max(ans, v1 + tmp.first * v2 * eps);
        //printf("%lf: %lf %lf (extra = %lf)\n",tmp.first, v1, v2, extra);
    }
    cout << setprecision(10) << fixed <<  ans + extra;
}