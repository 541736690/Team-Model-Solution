#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2


int n;
struct Pt {
    int x1, y1, x2, y2;

    void read() {
        cin >> x1 >> y1 >> x2 >> y2;
    }

} pt[N];

struct Ev {
    int l, r, x;
} ev[N];

int ys[N];

struct node {
    int sum, fp, len;

    void flip() {
        fp = !fp;
        sum = len - sum;
    }

    void merge(node &ls, node &rs) {
        sum = ls.sum + rs.sum;
    }
};


struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].fp) {
            if(l < r) {
                dat[ls(x)].flip();
                dat[rs(x)].flip();
            }
            dat[x].fp = 0;
        }
    }

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x].sum = 0;
            dat[x].fp = 0;
            dat[x].len = (l == n - 1 ? 0 : ys[l+1] - ys[l]);
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].len = dat[ls(x)].len + dat[rs(x)].len;
        dat[x].sum = 0;
        dat[x].fp = 0;
    }

    int query() {
        push_down(0, 0, n - 1);
        return dat[0].sum;
    }

    void update(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].flip();
            return ;
        }

        update(a, b, ls(x), l, mid);
        update(a, b, rs(x), mid + 1, r);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }
} tree;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        pt[i].read();
        ys[i * 2] = pt[i].y1;
        ys[i * 2 + 1] = pt[i].y2;
        ev[i * 2] = {pt[i].y1, pt[i].y2, pt[i].x1};
        ev[i * 2 + 1] = {pt[i].y1, pt[i].y2, pt[i].x2};
    }
    n *= 2;
    sort(ys, ys + n);
    sort(ev, ev + n, [](const Ev &ev1, const Ev &ev2) {
        return ev1.x < ev2.x;
    });
    tree.init(0, 0, n - 1);
    int r = 0;
    ll res = 0;
    int lasx = -1;
    for(int i = 0; i < n; i = r) {
        int curx = ev[i].x;
        res += 1LL * (curx - lasx) * tree.query();
        lasx = curx;
        while(r < n && ev[r].x == ev[i].x) {
            int lb = (int)(lower_bound(ys, ys + n, ev[r].l) - ys);
            int rb = (int)(lower_bound(ys, ys + n, ev[r].r) - ys);
            tree.update(lb, rb - 1, 0, 0, n - 1);
            r++;
        }
    }
    cout << res << endl;
}