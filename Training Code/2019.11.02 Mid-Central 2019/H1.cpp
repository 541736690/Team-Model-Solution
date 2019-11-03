#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

struct node {
    int ls, rs, sum;
} ns[N * 30];

int ncnt = 1;

int n, m;

int newnode(int val) {
    ns[ncnt].ls = ns[ncnt].rs = 0;
    ns[ncnt].sum = val;
    return ncnt++;
}

int newnode(int ls, int rs) {
    ns[ncnt].ls = ls;
    ns[ncnt].rs = rs;
    ns[ncnt].sum = (ls ? ns[ls].sum : 0) + (rs ? ns[rs].sum : 0);
    return ncnt++;
}

int x[N], zeros[N];

int build(int a[], int tl = 0, int tr = n - 1) {
    if(tl == tr) return newnode(a[tl]);
    int mid = (tl + tr) / 2;
    return newnode(build(a, tl, mid), build(a, mid + 1, tr));
}

int get_sum(int v, int l, int r, int tl = 0, int tr = n - 1) {
    if(tr < l || tl > r) return 0;
    if(l <= tl && tr <= r) return ns[v].sum;
    int tm = (tl + tr) / 2;
    return get_sum(ns[v].ls, l, r, tl, tm)
        + get_sum(ns[v].rs, l, r, tm + 1, tr);
}

int update(int v, int pos, int tl = 0, int tr = n - 1) {
    if(tl == tr) return newnode(ns[v].sum + 1);
    int tm = (tl + tr) / 2;
    if(pos <= tm) return newnode(update(ns[v].ls, pos, tl, tm), ns[v].rs);
    else return newnode(ns[v].ls, update(ns[v].rs, pos, tm+1, tr));
}


bool search(int v1, int v2, int tl, int tr, int l, int r) {
    if(tl == tr) {
//        cout << tl << " " << ns[v1].sum << " " << ns[v2].sum << endl;
        return true;
    }
    int lsum = ns[ns[v2].ls].sum - ns[ns[v1].ls].sum;
    int rsum = ns[ns[v2].rs].sum - ns[ns[v1].rs].sum;
    int tm = (tl + tr) / 2;
    if(lsum >= (r - l + 1) / 2 + 1) return search(ns[v1].ls, ns[v2].ls, tl, tm, l, r);
    if(rsum >= (r - l + 1) / 2 + 1) return search(ns[v1].rs, ns[v2].rs, tm + 1, tr, l, r);
    return false;
}

int num[N], b[N];
int vs[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        double a; cin >> a;
        num[i+1] = (int)(a * 1000000);
//        cout << num[i+1] << endl;
        b[i] = num[i+1];
    }

    sort(b, b + n);
    for(int i = 1; i <= n; i++) num[i] = (int)(lower_bound(b, b + n, num[i]) - b);
    vs[0] = build(zeros);
    for(int i = 1; i <= n; i++) {
        vs[i] = update(vs[i-1], num[i]);
    }

    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        cout << (search(vs[l-1], vs[r], 0, n - 1, l, r) ? "usable" : "unusable") << '\n';
    }
}