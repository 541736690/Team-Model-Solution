#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rep(i, l, r) for(int i = l; i < r; i++)
#define sz(x) x.size()

typedef long long ll;
const int N = (int)2e5 + 50;
typedef pair<ll, ll> P;
typedef vector<int> vi;


string str;

struct SuffixArray {
    vi sa, lcp, rk;
    SuffixArray(string& s, int lim=256) { // or basic_string<int>
        int n = sz(s) + 1, k = 0, a, b;
        vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
        sa = lcp = rk = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i,0,n) ws[x[i]]++;
            rep(i,1,lim) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
                    (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        rep(i,1,n) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k && k--, j = sa[rank[i] - 1];
                    s[i + k] == s[j + k]; k++);
        s = " " + s;
        for(int i = n - 1; i >= 1; i--) sa[i]++, rk[sa[i]] = i;

    }
};

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
    if(it != S.end()) res = min(res, abs(*it - x));
    if(it != S.begin()) res = min(res, abs(*(--it) - x));
    return res;
}

P getpair(int dis, int clo) {
    return make_pll(clo + dis, clo);
}

int merge(int i1, int i2) {
    i1 = idx[i1];
    i2 = idx[i2];
    if(S[i1].size() < S[i2].size()) {
        swap(i1, i2);
    }
    for(int x : S[i2]) {
        closest[i1] = min(closest[i1], get_min(x, S[i1]));
        S[i1].insert(x);
    }
    idx[i2] = i1;
    return i1;
}

int main() {
    cin >> str;
    int n = str.length();
    SuffixArray sa = SuffixArray(str);

    P res = {1, 1};

    for(int i = 2; i <= n; i++) {
        eve[sa.lcp[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        idx[i] = i;
        S[i].insert(i);
        closest[i] = N;
    }
    for(int h = n; h >= 1; h--) {
        for(int e : eve[h]) {
            int id = merge(sa.sa[e-1], sa.sa[e]);
            if(closest[id] < N) res = get_max(res, getpair(h, closest[id]));
        }
    }
    cout << res.first << "/" << res.second << endl;

}