#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 50;
int n;
int num[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    ld res = 0;
    ld sum = 0;
    for(int i = 0; i < n; i++) {
        sum += num[i];
        res = max(res, sum / (i + 1));
    }
    sum = 0;
    for(int i = n - 1; i >= 0; i--) {
        sum += num[i];
        res = max(res, sum / (n - i));
    }
    cout << fixed << setprecision(10) << res << endl;

}