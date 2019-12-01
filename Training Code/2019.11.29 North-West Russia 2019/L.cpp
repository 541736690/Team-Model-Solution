#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50, LOGN = 20;
typedef pair<ll, ll> P;

string str;

struct SA {
    int n;
    int rk[N], sa[N], ht[N];

    int mm[N];
    int st[LOGN][N];

    void build(string str) {
        n = str.length();
        str = " " + str;
        static int set[N], a[N];
        for(int i = 1; i <= n; i++) set[i] = str[i];
        sort(set + 1, set + n + 1);
        int *end = unique(set + 1, set + n + 1);
        for(int i = 1; i <= n; i++) a[i] = (int)(lower_bound(set + 1, end, str[i]) - set);

        static int fir[N], sec[N], tmp[N], buc[N];
        fill(buc, buc + n + 1, 0);

        for(int i = 1; i <= n; i++) buc[a[i]]++;
        for(int i = 1; i <= n; i++) buc[i] += buc[i-1];
        for(int i = 1; i <= n; i++) rk[i] = buc[a[i] - 1] + 1;

        for(int t = 1; t <= n; t *= 2) {
            for(int i = 1;i <= n; i++) fir[i] =rk[i];
            for(int i = 1; i <= n; i++) sec[i] = i + t > n ? 0 : rk[i + t];

            fill(buc, buc + n + 1, 0);
            for(int i = 1; i <= n; i++) buc[sec[i]]++;
            for(int i = 1; i <= n; i++) buc[i] += buc[i-1];
            for(int i = 1; i <= n; i++) tmp[n - (--buc[sec[i]])] = i;

            fill(buc, buc + n + 1, 0);
            for(int i = 1; i <= n; i++) buc[fir[i]]++;
            for(int i = 1; i <= n; i++) buc[i] += buc[i-1];
            for(int j = 1, i; j <= n; j++) i = tmp[j], sa[buc[fir[i]]--] = i;

            bool unique = true;
            for(int j = 1, i, last = 0; j <= n; j++) {
                i = sa[j];
                if(!last) rk[i] = 1;
                else if(fir[i] == fir[last] && sec[i] == sec[last]) rk[i] = rk[last], unique = false;
                else rk[i] = rk[last] + 1;

                last = i;
            }

            if(unique) break;
        }
        for(int i = 1, k = 0; i <= n; i++) {
            if(rk[i] == 1) k = 0;
            else {
                if(k > 0) k--;
                int j = sa[rk[i]-1];
                while(i + k <= n && j + k <= n && a[i + k] == a[j + k]) k++;
            }
            ht[rk[i]] = k;
        }

        mm[0] = -1;
        for(int i = 1; i <= n; i++) mm[i] = ((i & (i - 1)) == 0 ? mm[i-1] + 1 : mm[i-1]);
        for(int i = 1; i <= n; i++) {
            st[0][i] = ht[i];
        }
        for(int lg = 1; lg < LOGN; lg++) {
            for(int j = 1; j + (1 << lg) - 1 <= n; j++) {
                st[lg][j] = min(st[lg-1][j], st[lg-1][j+(1<<(lg-1))]);
            }
        }
    }
    int rmq(int l, int r) {
        int k = mm[r - l + 1];
        return min(st[k][l], st[k][r-(1 << k) + 1]);
    }

    int get_lcp(int l, int r) {
        l = rk[l], r = rk[r];
        if(l > r) swap(l, r);
        return rmq(l + 1, r);
    }

} sa, rsa;

P get_max(P p1, P p2) {
    if(p1.first * p2.second > p1.second * p2.first) return p1;
    return p2;
}

P make_pll(ll a, ll b) {
    ll g = __gcd(a, b);
    return {a / g, b / g};
}

set<int> S[N];
int idx[N];
int closest[N];
vector<int> eve[N];

int get_min(int x, set<int> &S) {
    int res = N;
    auto it = S.lower_bound(x);
    if(it != S.end()) res = min(res, *it);
    if(it != S.begin()) res = min(res, *(--it));
    return res;
}

P getpair(int dis, int clo) {
    return make_pll(clo + dis, clo);
}

int merge(int i1, int i2) {
    if(S[idx[i1]].size() < S[idx[i2]].size()) {
        swap(i1, i2);
    }
    for(int x : S[idx[i2]]) {
        closest[idx[i1]] = min(closest[idx[i1]], get_min(x, S[idx[i1]]));
        S[idx[i1]].insert(x);
    }
    idx[i2] = idx[i1];
}

int main() {
    cin >> str;
    sa.build(str);
    reverse(str.begin(), str.end());
    rsa.build(str);
    int n = str.length();

    P res = {1, 1};
    for(int len = 1; len <= n; len++) {
        int r = 0;
        for(int i = 1; i + len - 1 <= n; i = r) {
            r = i + len;
            while(r <= n && sa.get_lcp(r, i) >= len) r += len;
            int sum = r - i + (r <= n ? sa.get_lcp(i, r) : 0) +
                    (i - 1 >= 1 ? rsa.get_lcp(n + 1 - (i - 1), n + 1 - (i + len - 1)) : 0);
            res = get_max(res, make_pll(sum, len));
        }
    }
    for(int i = 2; i <= n; i++) {
        eve[sa.ht[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        idx[i] = i;
        closest[i] = N;

    }
    for(int h = n; h >= 1; h--) {
        for(int e : eve[h]) {
            int id = merge(sa.sa[id-1], sa.sa[id]);
            res = get_max(res, getpair(h, closest[id]));
        }
    }




    cout << res.first << "/" << res.second << endl;

}