#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50;

bool p[N];
int mu[N], pm[N], pms;

void get_mobius_sieve() {
    mu[1] = 1;
    fill(p, p + N, true);
    pms = 0;
    for(int i = 2; i < N; i++) {
        if(p[i]) {
            pm[pms++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < pms && i * pm[j] < N; j++) {
            p[i * pm[j]] = false;
            if(i % pm[j] == 0) {
                mu[i * pm[j]] = 0;
                break;
            }
            mu[i * pm[j]] = -mu[i];
        }
    }
}

int solve(int n) {
    if(n < 4) return 0;
    for(int i = 0; i < pms; i++) {
        if(p[n - pm[i]]) return solve(n - pm[i] - pm[i]) + 1;
    }
    return -1;
}

int main() {
    get_mobius_sieve();
    int n;
    cin >> n;
    cout << solve(n) << endl;

//    int res = 0, xi = -1;

//    double mxtime = 0;
//    for(int i = N; i >= 1; i--) {
//        double curtime = clock() / (double)CLOCKS_PER_SEC;
//        if(solve(i) > res) {
//            res = solve(i);
//            xi = i;
//        }
//        mxtime = max(mxtime, clock() / (double)CLOCKS_PER_SEC - curtime);
//        if(i % 10000 == 0) {
//            cout << i / 10000 << " " << mxtime << endl;
//        }
//        if(mxtime > 1) {
//            return 1;
//        }
//    }
//    cout << res << " " << xi << endl;

}