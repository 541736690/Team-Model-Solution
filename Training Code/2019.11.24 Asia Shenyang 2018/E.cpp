#include <bits/stdc++.h>
using namespace std;

#define ls(x) 2*x+1
#define rs(x) 2*x+2

typedef long long ll;
typedef pair<ll, int> P;
const ll INF = (ll)2e18 + 50;
const int N = (int)1e5 + 50;

struct Pval {
    P ps[2];
    void put(P p) {
        for(int i = 0; i < 2; i++) {
            if(p.first > ps[i].first) {
                swap(ps[i], p);
            }
            if(p.second == ps[i].second) return ;
        }
    }
};

struct Point {
    ll x, y;
} p[N];

int n, m;
int clan[N];
int cx[4] = {1, -1, 1, -1}, cy[4] = {1, -1, -1, 1};

struct node {
    Pval mx[4];

    node() {
        for(int j = 0; j < 4; j++) mx[j].ps[0] = mx[j].ps[1] = {-INF, -1};
    }

    void set(int idx) {
        for(int j = 0; j < 4; j++) {
            mx[j].ps[0] = {p[idx].x * cx[j] + p[idx].y * cy[j], clan[idx]};
            mx[j].ps[1] = {-INF, -1};
        }
    }

    void merge(node &L, node &R) {
        for(int i = 0; i < 4; i++) {
            mx[i] = L.mx[i];
            mx[i].put(R.mx[i].ps[0]);
            mx[i].put(R.mx[i].ps[1]);
        }
    }

    void print() {
        cout << "node info: " << endl;
        for(int i = 0; i < 4; i++) {
            cout << mx[i].ps[0].first << " " << mx[i].ps[0].second << " " << mx[i].ps[1].first << " " << mx[i].ps[1].second << endl;
        }
        cout << endl;
    }
};

struct Tree {
    node dat[4 * N];

    void init_dat(int l, int r, int x) {
        if(l == r) {
            dat[x].set(l);
            return ;
        }
        int mid = (l + r) / 2;
        init_dat(l, mid, ls(x));
        init_dat(mid + 1, r, rs(x));
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    void update(int pos, int x, int l, int r) {
        if(l == r) {
            dat[x].set(pos);
            return ;
        }
        int mid = (l + r) / 2;
        if(pos <= mid) update(pos, ls(x), l, mid);
        else update(pos, rs(x), mid + 1, r);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    node query(int a, int b, int x, int l, int r) {
        if(r < a || b < l) return node();

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        node res;
        node LHS = query(a, b, ls(x), l, mid);
        node RHS = query(a, b, rs(x), mid + 1, r);
        res.merge(LHS, RHS);
        return res;
    }
} tree;

void solve(int tcase) {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y >> clan[i];
    }
    tree.init_dat(0, n - 1, 0);
    cout << "Case #" << tcase << ":\n";
    for(int i = 0; i < m; i++) {
        int tp;
        cin >> tp;
        if(tp == 1) {
            int idx, x, y;
            cin >> idx >> x >> y; idx--;
            p[idx].x += x;
            p[idx].y += y;
            tree.update(idx, 0, 0, n - 1);
        }
        else if(tp == 2) {
            int idx, c;
            cin >> idx >> c; idx--;
            clan[idx] = c;
            tree.update(idx, 0, 0, n - 1);
        }
        else {
            int l, r;
            cin >> l >> r; l--, r--;
            node nd = tree.query(l, r, 0, 0, n - 1);

//            nd.print();
            ll res = 0;
            for(int j = 0; j < 4; j += 2) {
                if(nd.mx[j].ps[0].second != nd.mx[j+1].ps[0].second) {
                    res = max(res, 1LL * nd.mx[j].ps[0].first + nd.mx[j+1].ps[0].first);
                }
                else {
                    res = max(res, 1LL * nd.mx[j].ps[1].first + nd.mx[j+1].ps[0].first);
                    res = max(res, 1LL * nd.mx[j].ps[0].first + nd.mx[j+1].ps[1].first);
                }
            }
            cout << res << '\n';
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        solve(t);
    }
}