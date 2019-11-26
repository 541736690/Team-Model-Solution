#include <bits/stdc++.h>
using namespace std;

const int N = 1005, INF = (int)1e9 + 50;

int n;
int a[N], b[N];
int mn[N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    fill(mn, mn + n, INF);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mn[i] = min(mn[i], abs(a[i] - b[j]));
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++) res = max(mn[i], res);
    cout << res << endl;
}