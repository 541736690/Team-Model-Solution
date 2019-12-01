#include <bits/stdc++.h>
using namespace std;

const int N = 1005, INF = (int)1e9;

int n;
int x[N], y[N], h[N];
int xmin, xmax, ymin, ymax;

bool check(int ch) {
    xmin = ymin = -INF;
    xmax = ymax = INF;

    for(int i = 0; i < n; i++) {
        if(h[i] > ch) return false;
        int d = ch - h[i];
        xmin = max(xmin, x[i] - d);
        xmax = min(xmax, x[i] + d);
        ymin = max(ymin, y[i] - d);
        ymax = min(ymax, y[i] + d);
    }
    return xmin <= xmax && ymin <= ymax;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> h[i];

    int l = 0, r = (int)3e8, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    check(r);
    cout << xmin << " " << ymin << " " << r << endl;

}