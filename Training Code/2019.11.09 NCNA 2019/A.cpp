#include <bits/stdc++.h>
using namespace std;

typedef double ld;
const ld EPS = (ld)5e-5;
typedef long long ll;

struct Pt {
    ld x, y;
};

vector<Pt> pt[3];
ld solve(vector<Pt> &pts, ld x, ld y) {
    ld res = 0;
    for(auto p : pts) {
        res = max(res, hypot(p.x - x, p.y - y));
//        cnt++;
    }
    return res;
}

ld solve(vector<Pt> &pts, ld x) {
    ld l = -1005, r = 1005, mid1, mid2;
    while(l + EPS < r) {
        mid1 = l + (r - l) / 3;
        mid2 = r - (r - l) / 3;
        if(solve(pts, x, mid1) < solve(pts, x, mid2)) {
            r = mid2;
        }
        else l = mid1;
    }
    return solve(pts, x, (l + r) / 2);
}

ld solve(vector<Pt> &pts) {
    ld l = -1005, r = 1005, mid1, mid2;
    while(l + EPS < r) {
        mid1 = l + (r - l) / 3;
        mid2 = r - (r - l) / 3;
        if(solve(pts, mid1) < solve(pts, mid2)) {
            r = mid2;
        }
        else l = mid1;
    }
    return solve(pts, (l + r) / 2);
}

int main() {
    int n;
    cin >> n;
//    n = 5000;
    for(int i = 0; i < n; i++) {
        ld x, y, z;
        cin >> x >> y >> z;
//        x = y = z = 0.0;
        pt[0].push_back({x, y});
        pt[1].push_back({x, z});
        pt[2].push_back({y, z});
    }
    cout << fixed << setprecision(10) << 2 *  min(solve(pt[0]), min(solve(pt[1]), solve(pt[2]))) << endl;
//    cout << cnt << endl;
}